//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_ASTAR_H
#define FINAL_PROJECT_SECOND_ASTAR_H

#include "Searcher.h"

class AStar: public Searcher {

public:
    virtual string search(Searchable* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual string restore_solution(Searchable* searchable) = 0 ;
    int heuristic_func(State* current, State* goal) ;
};


#endif //FINAL_PROJECT_SECOND_ASTAR_H
