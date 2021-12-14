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
    
    char* client_request_message = (char*)malloc(MAXLINE*sizeof(char));

    n = recvfrom(udpServerSocket->sock, client_request_message, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,&len);
        
    //client_message.unFlatten(client_request_message);
    //char * message = (char*) client_message.getMessage().c_str();
    //int lsize = client_message.getMessageSize();

    string username = "";
    /*string username = receive_message();
    cout << username << endl;*/

    /*time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	char time_string[100];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, 50, "%B-%d-%Y", curr_tm);
	strftime(time_string, 50, "%T", curr_tm);

    string filename = username + "_" + date_string + "_" + time_string;
    
    char * tmp;
    getcwd(tmp, 256);
    
    

    filename = tmp +"/"+filename+".jpg";

    cout << filename << endl;*/

    FILE *pOutput = fopen("image2", "wb+"); //write to image file
    fwrite(client_request_message, 1, n, pOutput);

    return &client_message;
}

Message * Server:: doOperation(){
    
}

void Server:: sendReply (Message * _message){

    MessageType message_type= Reply;
    
    socklen_t len = sizeof(udpServerSocket-> peerAddr);  //len is value/resuslt

    //string reply = "Image Size: " + to_string(_message->getMessageSize()) + "KB";
    string reply = "Imaged Uploaded";\
    cout << reply << endl;

    sendto(udpServerSocket->sock, (char*)reply.c_str(), reply.length(), 
        MSG_CONFIRM, (const struct sockaddr *) &udpServerSocket->peerAddr, len);
}



void Server::serveRequest(){
    //auto future = std::async([this]()->Message*{getRequest();});
    
    //while(true){
       Message* client_message = getRequest();
       
       //doOperation();
       //sendReply(client_message);  
       
    //}

}

string Server::receive_message() {
    string username;
    socklen_t len;
    int n = recvfrom(udpServerSocket->sock, (char*)username.c_str(), MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,&len); 
    cout << "Got: " << username << endl;
    return username;
}


Server::~Server(){
    delete udpServerSocket;

}
