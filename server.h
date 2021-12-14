#include "udpserversocket.h"
#include "message.h"
#include <sstream>
#ifndef SERVER_H
#define SERVER_H

class Server {
private:
    UDPServerSocket * udpServerSocket;
    Message * getRequest();
    Message * doOperation();
    void sendReply (Message * _message);

public:
    Server(char * _listen_hostname, int _listen_port);
    void serveRequest();
    string receive_message();
    ~Server();
};
#endif // SERVER_H