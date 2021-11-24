#include "message.h"

Message:: Message(int operation, void * p_message, size_t p_message_size,int p_rpc_id){

}

Message:: Message(char * marshalled_base64){

}

char * Message:: marshal (){

}

int Message:: getOperation (){

}

int Message:: getRPCId(){

}

void * Message:: getMessage(){

}

size_t Message:: getMessageSize(){

}

MessageType Message:: getMessageType(){

}

void Message:: setOperation (int _operation){

}

void Message:: setMessage (void * message, size_t message_size){

}

void Message:: setMessageType (MessageType message_type){

}

Message:: ~Message(){

}