#include "message.h"

char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
#define SIZE 1000

Message:: Message(){
message_size=4096;
}

//CHANGED void * to char *
Message:: Message(MessageType p_message_type,int p_operation, char * p_message, size_t p_message_size,int p_rpc_id){
    message_type= p_message_type;
    operation = p_operation;
    message = p_message;
    message_size = p_message_size;
    rpc_id = p_rpc_id;
}

Message:: Message(char * marshalled_base64){
    message = marshalled_base64;
}

char * Message:: marshal (){
    char *marshalled_message = (char *) malloc(SIZE * sizeof(char));
    int msg_size = message_size;
    
    char* message_char= (char*) message;
    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp;
    int i, j, k = 0;
      
    for (i = 0; i < msg_size; i += 3) {
            val = 0, count = 0, no_of_bits = 0;
  
            for (j = i; j < msg_size && j <= i + 2; j++) {
                val = val << 8;
                val = val | message_char[j];
                count++;
            }
  
            no_of_bits = count * 8;
  
            padding = no_of_bits % 3;
  
            while (no_of_bits != 0) {
                if (no_of_bits >= 6) {
                    temp = no_of_bits - 6;
                    index = (val >> temp) & 63;
                    no_of_bits -= 6;        
                } else {
                    temp = 6 - no_of_bits;
                    index = (val << temp) & 63;
                    no_of_bits = 0;
                }
                marshalled_message[k++] = char_set[index];
            }
    }
    
    for (i = 1; i <= padding; i++) {
        marshalled_message[k++] = '=';
    }
  
    marshalled_message[k] = '\0';
  
    return marshalled_message;
}

int Message:: getOperation (){
    return operation;
}

int Message:: getRPCId(){
    return rpc_id;
}

void * Message:: getMessage(){      //CHANGED FROM void * to char *
    return message;
}

size_t Message:: getMessageSize(){
    return message_size;
}

MessageType Message:: getMessageType(){
    return message_type;
}

void Message:: setOperation (int _operation){
    operation = _operation;
}

void Message:: setMessage (void * message, size_t message_size){
    message = message;
    message_size = message_size;
}

void Message:: setMessageType (MessageType message_type){
    message_type = message_type; 
}

Message:: ~Message(){

}