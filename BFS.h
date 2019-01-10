//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_BFS_H
#define FINAL_PROJECT_SECOND_BFS_H

#include <map>
#include <string>
#include <vector>
#include "Searcher.h"

using namespace std ;

class BFS: public Searcher{

public:
    virtual string search(Searchable* searchable) ;
    virtual int getNumberOfNodesEvaluated() ;
    virtual string restore_solution(Searchable* searchable) ;
    string check_direction(State* current) ;

};


#endif //FINAL_PROJECT_SECOND_BFS_H
