#ifndef CLIENT_H
#define CLIENT_H

#include "udpclientsocket.h"
#include "message.h"
#include "sstream"

class Client {
private:
    UDPClientSocket * udpClientSocket;

public:
    Client(char * _hostname, int _port);
    void send_request(Message message);
    Message * execute(Message * _message);
    ~Client();
};
#endif // CLIENT_H 