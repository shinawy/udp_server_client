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
    myclient.send_request((char*)comm.c_str());
    }while (comm != "wq!");
    return 0; 
}
