#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClient.h"
#include "ClientHandler.h"
#include "StringReverse.h"
#include <string>

using namespace std ;


    int main(int argc, char *argv[]) {
        int c1 = stoi(argv[1]);

        Solver<string, string> *solver = new StringReverse() ;
        server_side::Server *A = new MySerialServer;
        ClientHandler *B = new MyTestClient(solver);
        A->open(c1, B);
        while(true){}

        return 0 ;
    }
