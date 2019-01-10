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
    string check_direction(State* current) ;
    int heuristic_func(State* current, State* next_vertex, State* goal, map<string, int>* cost_to_vertex_map) ;
    map<string, int> build_path_cost_map(unordered_map<string, State*>* vertex_map) ;
    bool find_in_vec(vector<State*>* vec, State* current) ;
    int find_lowest_cost(vector<State*>* vec, map<string,int>* cost_to_vertex_map) ;
};


#endif //FINAL_PROJECT_SECOND_ASTAR_H
