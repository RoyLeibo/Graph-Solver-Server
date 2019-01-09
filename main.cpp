#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClient.h"
#include "ClientHandler.h"
#include "StringReverse.h"
#include "Matrix.h"
#include "MyParallelServer.h"
#include <string>
#include <vector>

using namespace std ;

int main(int argc, char *argv[]) {
    int c1 = stoi(argv[1]);

    Solver<string, string> *solver = new StringReverse();
    server_side::Server *A = new MyParallelServer;
    ClientHandler *B = new MyTestClient(solver);
    A->open(c1, B);
    delete (solver);
    delete (A);
    delete (B);
    return 0;
}
