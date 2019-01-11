//
// Created by einat on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_DFS_H
#define FINAL_PROJECT_SECOND_DFS_H


#include <map>
#include <string>
#include <vector>
#include "Searcher.h"



using namespace std;

class DFS : public  Searcher
{
private:
    void searchDFS(map<string, vector<State*>> adjacent_map,map<string, bool> visited_map, State* current, State* goalState);
    string check_direction(State* current);
public:
    virtual string search(Searchable* searchable) ;
    virtual int getNumberOfNodesEvaluated() ;
    virtual string restore_solution(Searchable* searchable) ;

};


#endif //FINAL_PROJECT_SECOND_DFS_H
