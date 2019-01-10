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
    map<string, bool> visited ;

public:
    void init() ;
    virtual string search(Searchable searchable) ;
    virtual int getNumberOfNodesEvaluated() ;

};


#endif //FINAL_PROJECT_SECOND_BFS_H