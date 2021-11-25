#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std; 

#ifndef MESSAGE_H
#define MESSAGE_H

enum MessageType { Request, Reply};

class Message {
private:
    MessageType message_type;
    int operation;
    char * message;             //CHANGED FROM void * to char *
    size_t message_size;
    int rpc_id;

public:
    Message(int operation, char * p_message, size_t p_message_size,int p_rpc_id); //CHANGED FROM void * to char *
    Message(char * marshalled_base64);
    char * marshal ();
    int getOperation ();
    int getRPCId();
    char * getMessage();    //CHANGED FROM void * to char *
    size_t getMessageSize();
    MessageType getMessageType();
    void setOperation (int _operation);
    void setMessage (void * message, size_t message_size);
    void setMessageType (MessageType message_type);

~Message();

};

#endif // MESSAGE_H