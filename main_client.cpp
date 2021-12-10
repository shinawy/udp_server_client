#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"
#include <string>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "user.h"

int main() {

    cout << "Welcome to The Online Image Sharing Server\n"; 
    
    string hostname = "macoclient";


    Client myclient((char*)hostname.c_str(), 8080);
    
    cout << "1) Login\n";
    cout << "2) Register User\n"; 
    string username, password;

    int op0;
    cin >> op0;
    if (op0 == 1) {
            cout << "Enter Username: \n";
            cin >> username;
            cout << "Enter Password: \n";
            cin >> password;

    } else if (op0 == 2) {
            cout << "Enter Username: \n";
            cin >> username;
            cout << "Enter Password: \n";
            cin >> password;
    }

    User usr (username, password);

    int op;           

    do{
        cout << "[*]------------------------------------------------------[*]\n";
        cout << "Enter number for the option you want: \n";
        cout << "1) Upload an Image\n";
        cout << "2) View Your Images\n";
        cout << "3) Removre Viewers\n";
        cout << "3) Edit Viewers Quota\n";
        cout << "5) View an Image\n";
        cout << "6) Exit\n";
        cout << "[*]------------------------------------------------------[*]\n";
         
        cin >> op;

        switch (op) {
            case 1: 
            {
                printf("Enter Image Path: \n");
                string comm;
                cin >> comm;
                Message* client_message = usr.upload_image(comm); 
                myclient.send_request(*client_message);
            }
            case 2: 
            {
                usr.view_owned_images();
            }
                
            
            case 3: 
            {
                cout << "Enter Viewer username: \n";
                string user;
                cin >> user;
                usr.remover_viewer(user);
            }
            case 4:
            {
                cout << "Enter Viewer username: \n";
                string user;
                cin >> user;
                usr.edit_viewer_quota(user);
            }
            case 5: 
             
                usr.view_image();

            case 6:
                return 0;
        }


    } while (op != 6);

    return 0; 
}
