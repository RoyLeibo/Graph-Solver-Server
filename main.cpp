#include <iostream>
#include "Server.h"
#include "MySrialServer.h"
#include "MyTestClient.h"
#include "ClientHandler.h"
namespace boot {


    int main(int argc, char* argv[]) {
        server_side::Server *A = new MySrialServer;
        ClientHandler *B = new MyTestClient;
        A->open(((*argv[0]) -'0'), *B);
    }
}