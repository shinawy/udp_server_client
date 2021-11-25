#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"
#include <string>

int main(){
    cout<<"hello from client\n"; 
    Client myclient("macoclient", 8080);
    // char comm[1024];
    string comm; 
    do{
    getline(cin,comm);
    MessageType message_type= Request;
    Message* client_message= new Message(message_type,0, (char*)comm.c_str(), comm.length()+1,1);
    myclient.send_request(client_message);
    }while (comm != "wq!");
    return 0; 
}
