
#ifndef FINAL_PROJECT_SECOND_MAIN_H
#define FINAL_PROJECT_SECOND_MAIN_H

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
#include "BestFS.h"

#include "MyClientHandler.h"
#include "GraphSolver.h"

static pthread_mutex_t mutex1 ;
static pthread_mutex_t mutex2 ;
static pthread_mutex_t mutex3 ;

namespace boot {

    class Main {
    public:
        void main(int port) {
            Solver<vector<string>, string> *solver = new GraphSolver();
            server_side::Server *A = new MyParallelServer;
            ClientHandler *B = new MyClientHandler(solver);
            A->open(port, B);
            cout << "end of main" << endl ;
//            delete (solver);
//            delete (A);
//            delete (B);

//            vector<string> matrix_vec ;
//            matrix_vec.push_back("5,1,5,1,1,1,5") ;
//            matrix_vec.push_back("5,1,5,1,5,1,5") ;
//            matrix_vec.push_back("5,1,5,1,5,1,5") ;
//            matrix_vec.push_back("5,1,5,5,5,1,5") ;
//            matrix_vec.push_back("1,1,1,1,1,1,5") ;
//            matrix_vec.push_back("1,5,5,5,5,5,5") ;
//            matrix_vec.push_back("1,1,1,1,1,1,1") ;
//            matrix_vec.push_back("0,0") ;
//            matrix_vec.push_back("6,6") ;
//            Searchable* mat = new Matrix(matrix_vec) ;
//            Searcher* bfs = new BFS() ;
//            cout << bfs->search(mat) << endl ;

        }

    };

}


#endif //FINAL_PROJECT_SECOND_MAIN_H
