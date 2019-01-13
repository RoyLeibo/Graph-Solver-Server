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
#include "Main.h"
#include <string>
#include <vector>

using namespace std ;

int main(int argc, char *argv[]) {
    boot::Main().main(stoi(argv[1])) ;


    return 0;
}
