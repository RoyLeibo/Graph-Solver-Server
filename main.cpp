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
    int c1 = stoi(argv[1]);

//    Solver<string, string> *solver = new StringReverse();
//    server_side::Server *A = new MyParallelServer;
//    ClientHandler *B = new MyTestClient(solver);
//    A->open(c1, B);
//    delete (solver);
//    delete (A);
//    delete (B);

vector<string> matrix_vec ;
matrix_vec.push_back("1,2,3,3,2") ;
    matrix_vec.push_back("1,2,3,3,2") ;
    matrix_vec.push_back("1,2,3,3,2") ;
    matrix_vec.push_back("2,3,1,4,3") ;
    matrix_vec.push_back("3,2,1,5,4") ;
    matrix_vec.push_back("1,3") ;
    matrix_vec.push_back("3,2") ;
    Searchable* mat = new Matrix(matrix_vec) ;
    Searcher* bfs = new BFS() ;
    cout << bfs->search(mat) << endl ;
    return 0;
}
