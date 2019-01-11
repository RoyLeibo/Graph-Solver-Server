

#ifndef FINAL_PROJECT_SECOND_SEARCHERSOLVER_H
#define FINAL_PROJECT_SECOND_SEARCHERSOLVER_H

#include "Matrix.h"
#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include <string>

using namespace std ;

class SearcherSolver: public Solver<Searchable*, string> {
    Searcher* searcher ;

public:
    virtual string solve(Searchable* problem) ;
    virtual ~SearcherSolver();
};


#endif //FINAL_PROJECT_SECOND_SEARCHERSOLVER_H
