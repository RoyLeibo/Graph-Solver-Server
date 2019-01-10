//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_SEARCHERSOLVER_H
#define FINAL_PROJECT_SECOND_SEARCHERSOLVER_H

#include "Matrix.h"
#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"

class SearcherSolver: public Solver<Searchable, string> {
    Searcher* searcher ;

public:
    string solve(Searchable problem) ;
};


#endif //FINAL_PROJECT_SECOND_SEARCHERSOLVER_H
