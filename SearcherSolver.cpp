
#include "SearcherSolver.h"
#include "AStar.h"

string SearcherSolver::solve(Searchable* problem) {
    this->searcher = new AStar() ;
    return this->searcher->search(problem)   ;
}

SearcherSolver::~SearcherSolver(){}
