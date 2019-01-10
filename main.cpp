#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClient.h"
#include "ClientHandler.h"
#include "StringReverse.h"
#include "Matrix.h"
#include "MyParallelServer.h"
#include "Searcher.h"
#include "BFS.h"
#include <string>
#include <vector>

using namespace std ;

int main(int argc, char *argv[]) {
//    int c1 = stoi(argv[1]);
//
//    Solver<string, string> *solver = new StringReverse();
//    server_side::Server *A = new MyParallelServer;
//    ClientHandler *B = new MyTestClient(solver);
//    A->open(c1, B);
//    delete (solver);
//    delete (A);
//    delete (B);
//    return 0;

    vector<string> matrix_vec ;
    matrix_vec.push_back("1, 1, 100") ;
    matrix_vec.push_back("7, 6, 12") ;
    matrix_vec.push_back("5, 4, 10") ;
    matrix_vec.push_back("0,0") ;
    matrix_vec.push_back("2,2") ;
    Searchable* matrix = new Matrix(matrix_vec) ;
    Searcher* s = new BFS() ;
    cout << s->search(matrix) << endl ;
}
