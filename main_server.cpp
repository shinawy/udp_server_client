#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"

int main() {
    cout <<"hello from server\n";
    // Message* message= new Message();
    Server myserver("macoserver",8080);
    myserver.serveRequest();
    return 0; 
}
