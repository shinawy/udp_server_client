#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"
#include <string>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "curlapi.h"
#ifndef USER_H
#define USER_H


class User {
private:
    string base_url="https://gizt35h8fh.execute-api.us-east-2.amazonaws.com/v1/";

    string username, password;

public:
    User();
    User(string username, string password);
    Json::Value login(string username, string password);
    Json::Value register_user(string username, string password, string fname, string lname);
    void set_username(string _username);
    void set_password(string _password);
    Message* upload_image(string path);
    Json::Value view_owned_images();
    Json::Value remover_viewer(string viewer_username);
    Json::Value edit_viewer_quota(string viewer_username);
    Json::Value view_image();
    ~User();
};
#endif // USER_H