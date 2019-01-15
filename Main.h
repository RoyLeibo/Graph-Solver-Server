
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
//            Solver<vector<string>, string> *solver = new GraphSolver();
//            server_side::Server *A = new MyParallelServer;
//            ClientHandler *B = new MyClientHandler(solver);
//            A->open(port, B);
//            cout << "end of main" << endl ;
//            delete (solver);
//            delete (A);
//            delete (B);

            vector<string> matrix_vec ;
            string line ;
            for (int i = 0 ; i < 50; i++) {
                for (int j = 0 ; j < 50; j++) {
                    line += to_string(rand() % 20 - 1)+',' ;

                }
                line.erase(line.length()-1, 1) ;
                matrix_vec.push_back(line) ;
                cout << line << endl;
                line = "" ;
            }
            matrix_vec.push_back("0,0") ;
            matrix_vec.push_back("49,49") ;
//            matrix_vec.push_back("0,0") ;
//            matrix_vec.push_back("49,49") ;
//            matrix_vec.push_back("5,10,5,4,7,2,5,") ;
//            matrix_vec.push_back("5,1,5,1,5,1,5,10,") ;
//            matrix_vec.push_back("5,1,5,1,5,1,5") ;
//            matrix_vec.push_back("5,1,5,5,5,1,5") ;
//            matrix_vec.push_back("1,1,1,1,1,1,5") ;
//            matrix_vec.push_back("1,5,5,5,5,5,5") ;
//            matrix_vec.push_back("1,1,1,1,1,1,1") ;
//            matrix_vec.push_back("0,0") ;
//            matrix_vec.push_back("6,6") ;
            cout << "a" << endl ;
            Searchable* mat = new Matrix(matrix_vec) ;
            Searcher* bfs = new DFS() ;
            cout << bfs->search(mat) << endl ;
            cout << bfs->getNumberOfNodesEvaluated()<< endl ;

        }

    };

}

#endif //FINAL_PROJECT_SECOND_MAIN_H
