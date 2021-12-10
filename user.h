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

#ifndef USER_H
#define USER_H

class User {
private:
    string username, password;

public:
    User();
    User(string username, string password);
    bool login(string username, string password);
    bool register_user(string username, string password);
    void set_username(string _username);
    void set_password(string _password);
    Message* upload_image(string path);
    void view_owned_images();
    void remover_viewer(string viewer_username);
    void edit_viewer_quota(string viewer_username);
    void view_image();
    ~User();
};
#endif // USER_H