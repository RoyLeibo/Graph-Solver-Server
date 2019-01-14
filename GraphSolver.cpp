//
// Created by einat on 1/14/19.
//

#include "GraphSolver.h"

using namespace std ;

GraphSolver::GraphSolver()
{
    this->fileCacheManager = new FileCacheManager("graph_solution.csv");
    this->searcher = new BestFS();

}

string GraphSolver::solve(std::vector<std::string> problem)
{

}