#include "curlapi.h"


string base_url="https://gizt35h8fh.execute-api.us-east-2.amazonaws.com/v1/";

std::future<std::string> invoke(std::string const& url, std::string const& body) {
  return std::async(std::launch::async,
    [](std::string const& url, std::string const& body) mutable {
      std::list<std::string> header;
      header.push_back("Content-Type: application/json");

      curlpp::Cleanup clean;
      curlpp::Easy r;
      r.setOpt(new curlpp::options::Url(url));
      r.setOpt(new curlpp::options::HttpHeader(header));
      r.setOpt(new curlpp::options::PostFields(body));
      r.setOpt(new curlpp::options::PostFieldSize(body.length()));

      std::ostringstream response;
      r.setOpt(new curlpp::options::WriteStream(&response));

      r.perform();

      return std::string(response.str());
    }, url, body);
}


Json::Value call_api_json(std::string const& url, std::string const& body){

std::future<string> response= invoke(url, body);
string  res_str= response.get();
// cout<<"Response:\n" <<res_str<<endl;

Json::Reader jsread;
Json:: Value jsvalue;

jsread.parse(res_str, jsvalue);

return jsvalue;
}

string generate_body(vector<string> keys, vector<string> values){

string body="{";

for (int i=0; i< keys.size(); i++){
  if (i==keys.size()-1)
    body=body+"\""+keys[i]+"\": " + "\""+values[i]+"\"";
  else 
    body=body+"\""+keys[i]+"\": " + "\""+values[i]+"\",";
}
body=body+" }";

return body;

}