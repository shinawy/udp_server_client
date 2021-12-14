#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"

int main() {
    cout <<"Welcome to The Online Image Sharing Server\n";
    
    Server myserver("macoserver", 8080);

    myserver.serveRequest();
    
    return 0; 
}
