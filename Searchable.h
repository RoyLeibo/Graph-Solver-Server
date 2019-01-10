//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_SEARCHABLE_H
#define FINAL_PROJECT_SECOND_SEARCHABLE_H

#include <list>
#include <vector>
#include "State.h"

class Searchable {
    State* entry_vertex ;
    State* exit_vertex ;

public:
    virtual State* getInitialState() = 0;
    virtual State* getGoalState() = 0;
    virtual vector<State*> getAllPossibleStates(State* s) = 0;
    virtual map<string, vector<State*>>build_adjacent_map() = 0 ;
    virtual map<string, bool> create_visited_map() = 0 ;
    virtual void set_visited_map(string index) = 0 ;

};


#endif //FINAL_PROJECT_SECOND_SEARCHABLE_H
