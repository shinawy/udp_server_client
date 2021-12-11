#include "server.h"
#define MAXLINE 65535

Server::Server(char * _listen_hostname, int _listen_port){
    udpServerSocket = new UDPServerSocket();

    bool x  = udpServerSocket -> initializeServer(_listen_hostname, _listen_port);
    if (x) {
        printf("Server Intialized.\n");
    } else {
        printf("Error: Server Not Intialized.\n");
    }
}

Message* Server:: getRequest(){
    int n;
    socklen_t len;
    
    Message client_message;
    
    char* client_request_message = new char[MAXLINE];

    n = recvfrom(udpServerSocket->sock, client_request_message, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,&len);


    client_message.unFlatten(client_request_message);

    char * message = (char*) client_message.getMessage().c_str();
    int lsize = client_message.getMessageSize();
    
    FILE *pOutput = fopen("image2.jpg", "wb+"); //write to image file
    fwrite(message, 1, lsize, pOutput); 

    return &client_message;
}

Message * Server:: doOperation(){

}

void Server:: sendReply (Message * _message){

    MessageType message_type= Reply;
    
    socklen_t len = sizeof(udpServerSocket-> peerAddr);  //len is value/resuslt

    string reply = "Image Size: " + to_string(_message->getMessageSize()) + "KB";

    sendto(udpServerSocket->sock, (char*)reply.c_str(), reply.length(), 
        MSG_CONFIRM, (const struct sockaddr *) &udpServerSocket->peerAddr, len);
}



void Server::serveRequest(){
    //auto future = std::async([this]()->Message*{getRequest();});
    
    while(true){
       Message* client_message = getRequest();
       doOperation();
       sendReply(client_message);  
    }

}

Server::~Server(){
    delete udpServerSocket;

}
