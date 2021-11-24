#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"

int main(){
    cout<<"hello from client\n"; 
    Client myclient("macoclient", 8080);
    myclient.send_request("happy thanksgiving\n");

    return 0; 
}
