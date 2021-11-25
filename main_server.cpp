#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"

int main() {
    cout <<"hello from server\n";
    Server myserver("macoserver",8080);
    myserver.serveRequest();
    return 0; 
}
