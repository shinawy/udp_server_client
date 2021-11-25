#include "server.h"
#define MAXLINE 1024

Server::Server(char * _listen_hostname, int _listen_port){
   udpServerSocket = new UDPServerSocket();

    bool x  = udpServerSocket -> initializeServer(_listen_hostname, _listen_port);
    if (x) {
        printf("Server Intialized.\n");
    } else {
        printf("Error: Server Not Intialized.\n");
    }
}

void Server::serveRequest(){
// int len, n;
int n;
socklen_t len;
   char* hello_server= (char *)"This is the server\n";
    len = sizeof(udpServerSocket-> peerAddr);  //len is value/resuslt
    cout<<"len: "<<len<<endl;
   char buffer[MAXLINE];
   while(true){

    n = recvfrom(udpServerSocket->sock, (char *)buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,&len);

       buffer[n] = NULL;

    printf("Client : %s\n", buffer);
    sendto(udpServerSocket->sock, (const char *)hello_server, strlen(hello_server), 
        MSG_CONFIRM, (const struct sockaddr *) &udpServerSocket->peerAddr,
            len);
    // printf("Hello message sent.\n");
   }

}

Server::~Server(){
    delete udpServerSocket;

}
