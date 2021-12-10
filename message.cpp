#include "message.h"

char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
#define SIZE 1000

Message:: Message(){

}

Message:: Message(MessageType p_message_type,int p_operation, string p_message, size_t p_message_size,int p_rpc_id){
    message_type= p_message_type; 
    operation = p_operation;
    message = p_message;
    message_size = p_message_size;
    rpc_id = p_rpc_id;
    flattened = "";
}

Message:: Message(char * marshalled_base64){
    message = marshalled_base64;
}

char * Message:: marshal (){
    char *marshalled_message = (char *) malloc(SIZE * sizeof(char));
    int msg_size = message_size;
    
    char* message_char=  (char*)message.c_str();
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

char * Message:: demarshal (){
    char* unmarshalled_message;
    unmarshalled_message = (char*)malloc(sizeof(char) * SIZE);
 
    int i, j, k = 0;
    int num = 0;
    int count_bits = 0;
    
    for (i = 0; i < message_size; i += 4) {
        num = 0, count_bits = 0;
        for (j = 0; j < 4; j++) {
             
            if (message[i + j] != '=')
            {
                num = num << 6;
                count_bits += 6;
            }

            if (message[i + j] >= 'A' && message[i + j] <= 'Z')
                num = num | (message[i + j] - 'A');

            else if (message[i + j] >= 'a' && message[i + j] <= 'z')
                num = num | (message[i + j] - 'a' + 26);

            else if (message[i + j] >= '0' && message[i + j] <= '9')
                num = num | (message[i + j] - '0' + 52);
 
            else if (message[i + j] == '+')
                num = num | 62;
 
            else if (message[i + j] == '/')
                num = num | 63;
            
            else {
                num = num >> 2;
                count_bits -= 2;
            }
        }
 
        while (count_bits != 0)
        {
            count_bits -= 8;
            unmarshalled_message[k++] = (num >> count_bits) & 255;
        }
    }
 
    unmarshalled_message[k] = '\0';
 
    return unmarshalled_message;
}

void Message:: encrypt() {
    key = rand();
    
    char* encrypted = new char;

    for (int i=0;i<message.length();i++) {
        if (isupper(message[i])) {
            encrypted += char(int(message[i]+key-65)%26 +65);
        } else {
            encrypted += char(int(message[i]+key-97)%26 +97);
        }
    }
    
    message = encrypted;
}

void Message:: decrypt() {
    char* plain = new char;
    for (int i=0;i<message.length();i++) {
        if (isupper(message[i])) {
            plain += char(int(message[i]-key-65)%26 +65);
        } else {
            plain += char(int(message[i]-key-97)%26 +97);
        }
    }
    message = plain;
}

bool Message::Flatten() {
    flattened = "";
    //flattened+=rpc_id;
    //flattened+=seperator;
    //flattened+=to_string(operation);
    //flattened+=seperator;
    flattened+=to_string(message_size);
    flattened+=seperator;
    flattened+=to_string((int)message_type);
    flattened+=seperator;
    flattened+=message;
    flattened+='\0';

    return true;
}

bool Message::unFlatten(string s)
{
	if(s=="")
	{
		perror("Nothing is there to be unflattened\n");
		return false;
	}
	stringstream ss(s);
	string tmp;
	//ss>>rpc_id;	
	//ss>>tmp;
	//operation=stoi(tmp);
    ss>>tmp;
	message_size=stoi(tmp);
	ss>>tmp;
	message_type=(MessageType)stoi(tmp);
	message="";
	char c;

	while(ss.get(c))
	{
		message+=c;
	}
	if(message.length()>0)message.erase(0,1);
}

string Message::getFlattenedMessage()
{
	return flattened;
}

int Message:: getOperation (){
    return operation;
}

string Message:: getRPCId(){
    return rpc_id;
}

string Message:: getMessage(){ 
    return message;
}

size_t Message:: getMessageSize(){
    return message_size;
}

MessageType Message:: getMessageType(){
    return message_type;
}

void Message:: setOperation (int p_operation){
    operation = p_operation;
}

void Message:: setMessage (char * p_message, size_t p_message_size){
    message = p_message;
    message_size = p_message_size;
}

void Message:: setMessageType (MessageType p_message_type){
    message_type = p_message_type; 
}

void Message::print_message_info(){
    cout<<"Message Info:   \n";
    cout<<"Message: "<<message<<endl;
    cout<<"Message Type: "<< message_type<<endl;
    cout<<"Message Operation: "<<operation<<endl;
    cout<<"Message RPCID: "<<rpc_id<<endl; 
    cout<<"END OF MESSAGE INFO......"<<endl;
}

Message:: ~Message(){

}