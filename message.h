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
#include <filesystem>
#include <sys/stat.h>
#include <sys/types.h>
#include <chrono>
#include <ctime>


using namespace std; 


#ifndef MESSAGE_H
#define MESSAGE_H

enum MessageType { Request, Reply};

class Message {

private:
    friend class boost::serialization::access;
    template <class Archive> void serialize(Archive& ar, unsigned) {
        ar &message_type &operation &message &message_size &rpc_id;
    }
    MessageType message_type;
    int operation;
    string message;              //CHANGED FROM void * to char *
    string flattened;
    size_t message_size;
    string rpc_id;
    int key;
    const char seperator = ' ';

public:
    Message();
    Message(MessageType message_type,int operation, string p_message, size_t p_message_size,int p_rpc_id); //CHANGED FROM void * to char *
    Message(char * marshalled_base64);
    char * marshal ();
    char * demarshal ();
    void encrypt();
    void decrypt();
    int getOperation ();
    string getRPCId();
    bool Flatten();
    bool unFlatten(string s);
    string getFlattenedMessage();
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