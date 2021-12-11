#include "user.h"

User:: User(){

}

User:: User(string _username, string _password){
    username = _username;
    password = _password;
}

bool User::login(string _username, string _password) {
    //LOGIN API
}

bool User::register_user(string _username, string _password) {
    //LOGIN API
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


void User::view_owned_images() {

}

void User::remover_viewer(string viewer_username) {

}

void User::edit_viewer_quota(string viewer_username) {

}

void User::view_image() {

}


User::~User(){

}