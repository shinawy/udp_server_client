#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <iomanip>
#define MaxNum 1024
using namespace std; 


#ifndef MESSAGE_H
#define MESSAGE_H

enum MessageType { Request, Reply};

class Message {

public:
    friend class boost::serialization::access;
    template <class Archive> void serialize(Archive& ar, unsigned) {
        ar &message_type &operation &message &message_size &rpc_id;
    }
    MessageType message_type;
    int operation;
    string message;              //CHANGED FROM void * to char *
    size_t message_size;
    int rpc_id;

public:
    Message();
    Message(MessageType message_type,int operation, char * p_message, size_t p_message_size,int p_rpc_id); //CHANGED FROM void * to char *
    Message(char * marshalled_base64);
    char * marshal ();
    int getOperation ();
    int getRPCId();
    string getMessage();    //CHANGED FROM void * to char *
    size_t getMessageSize();
    MessageType getMessageType();
    void setOperation (int _operation);
    void setMessage (char * message, size_t message_size);
    void setMessageType (MessageType message_type);
    void print_message_info();

~Message();

};

#endif // MESSAGE_H