#include "user.h"

User:: User(){

}

User:: User(string _username, string _password){
    username = _username;
    password = _password;
}

Json::Value User::login(string _username, string _password) {
    //LOGIN API

    vector<string> keys= {"username", "password"};
    vector<string> values= {_username,_password};
    string url= "dist_sign_in";
    string body= generate_body(keys,values);
    cout<<"url_sign_in: "<<url<<endl<<"body: "<<body<<endl;

    Json::Value jsvalue= call_api_json(base_url+url,body);
    return jsvalue;
}

Json::Value User::register_user(string _username, string _password, string fname, string lname) {
    //Sign Up API  
    vector<string> keys= {"username", "password", "first_name", "last_name"};
    vector<string> values= {_username,_password, fname, lname};
    string url= "dist_sign_up";
    string body= generate_body(keys,values);
    cout<<"url_sign_up: "<<url<<endl<<"body: "<<body<<endl;

    Json::Value jsvalue= call_api_json(base_url+url,body);
    return jsvalue;

}

Message* User::upload_image(string path) {
        std::ifstream fin(path, std::ios::in | std::ios::binary);
        std::ostringstream oss;
        oss << fin.rdbuf();
        std::string data(oss.str());

        int size = data.length();
     
        MessageType message_type= Request;
        
        Message* client_message= new Message(message_type, 0, data, size, 1);
    
        return client_message;
}


Json::Value User::view_owned_images() {

}

Json::Value User::remover_viewer(string viewer_username) {

}

Json::Value User::edit_viewer_quota(string viewer_username) {

}

Json::Value User::view_image() {

}


User::~User(){

}