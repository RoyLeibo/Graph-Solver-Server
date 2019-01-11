//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_ASTAR_H
#define FINAL_PROJECT_SECOND_ASTAR_H

#include "Searcher.h"

class AStar: public Searcher {

public:
    virtual string search(Searchable* searchable) ;
    virtual int getNumberOfNodesEvaluated() ;

private:
    virtual string restore_solution(Searchable* searchable) ;
    string check_direction(State* current) ;
    map<string, int> build_g_map(unordered_map<string, State*>* vertex_map) ;
    map<string, double> build_f_map(unordered_map<string, State*>* vertex_map) ;
    int find_in_vec(vector<State*>* vec, State* current) ;
    vector<State*>::iterator find_lowest_cost(vector<State*>* vec, map<string,double>* cost_to_vertex_map) ;

};

#endif //FINAL_PROJECT_SECOND_ASTAR_H
