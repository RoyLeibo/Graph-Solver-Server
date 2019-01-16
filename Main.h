
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
#include <iterator>
#include <random>

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
            delete(A) ;
//
//            vector<string> matrix_vec ;
//            string line ;
//            std::random_device rd;
//            std::mt19937 gen(rd()) ;
//            std::uniform_int_distribution<> dis(-1, 20);
//            for (int i = 0 ; i < 55; i++) {
//                for (int j = 0 ; j < 55; j++) {
//                line += to_string(dis(gen)) + ',' ;
//                }
//                line.erase(line.length()-1, 1) ;
//                matrix_vec.push_back(line) ;
//                cout << line << endl;
//                line = "" ;
//            }
//            matrix_vec.push_back("0,0") ;
//            matrix_vec.push_back("54,54") ;
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
//            Searchable* mat = new Matrix(matrix_vec) ;
//            Searcher* bestfs = new BestFS() ;
//
//            cout << "Best First Search:" << endl ;
//            cout << bestfs->search(mat) << endl ;
//            cout << bestfs->getNumberOfNodesEvaluated()<< endl ;
//
//            cout<< "\n" << "DFS:" << endl;
//            Searcher* dfs = new DFS() ;
//            cout << dfs->search(mat) << endl ;
//            cout << dfs->getNumberOfNodesEvaluated()<< endl ;
//
//            cout<< "\n" << "BFS:" << endl ;
//            Searcher* bfs = new BFS() ;
//            cout << bfs->search(mat) << endl ;
//            cout << bfs->getNumberOfNodesEvaluated()<< endl ;
//
//            cout<< "\n" << "A*:" << endl ;
//            Searcher* astar = new AStar() ;
//            cout << astar->search(mat) << endl ;
//            cout << astar->getNumberOfNodesEvaluated()<< endl ;



        }

    };

}

#endif //FINAL_PROJECT_SECOND_MAIN_H
