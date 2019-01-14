//
// Created by einat on 1/14/19.
//

#ifndef FINAL_PROJECT_SECOND_GRAPHSOLVER_H
#define FINAL_PROJECT_SECOND_GRAPHSOLVER_H

#include "Solver.h"
#include <string>
#include "FileCacheManager.h"
#include "Searcher.h"
#include "Searchable.h"
#include "BestFS.h"
#include "Matrix.h"
#include "vector"

class GraphSolver : public Solver<std::string,std::vector<std::string>> {
    private:
        FileCacheManager *fileCacheManager;
        Searchable *searchable;
        Searcher *searcher;
    public:
        GraphSolver();
            virtual std::string solve(std::vector<std::string> problem);

};


#endif //FINAL_PROJECT_SECOND_GRAPHSOLVER_H
