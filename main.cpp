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
#include "AStar.h"
#include "DFS.h"
#include "SearcherSolver.h"
#include "MyClientHandler.h"
#include <string>
#include <vector>

using namespace std ;

int main(int argc, char *argv[]) {
//    int c1 = stoi(argv[1]);
//    Solver<Searchable*, string> *solver = new SearcherSolver();
//    server_side::Server *A = new MyParallelServer;
//    ClientHandler *B = new MyClientHandler(solver);
//    A->open(c1, B);
//    delete (solver);
//    delete (A);
//    delete (B);

vector<string> matrix_vec ;
    matrix_vec.push_back("0,201,10,6") ;
    matrix_vec.push_back("0,210,0,1,2") ;
    matrix_vec.push_back("0,90,0,0,0") ;
    matrix_vec.push_back("0,0,1,10,9") ;
    matrix_vec.push_back("0,0,10,0,0") ;
    matrix_vec.push_back("1,2") ;
    matrix_vec.push_back("4,3") ;
    Searchable* mat = new Matrix(matrix_vec) ;
    Searcher* bfs = new AStar() ;
    cout << bfs->search(mat) << endl ;
    return 0;
}
