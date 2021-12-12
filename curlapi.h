#ifndef CURLAPI_H
#define CURLAPI_H

#include <sstream>
#include <string>
#include <iostream>
#include <curlpp/Easy.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <future>
#include <vector>
#include <jsoncpp/json/json.h>
using namespace std;



std::future<std::string> invoke(std::string const& url, std::string const& body);
Json::Value call_api_json(std::string const& url, std::string const& body);
string generate_body(vector<string> keys, vector<string> values);

#endif
