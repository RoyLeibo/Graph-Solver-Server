//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_SEARCHABLE_H
#define FINAL_PROJECT_SECOND_SEARCHABLE_H

#include <list>
#include "State.h"

class Searchable {
public:
    virtual State* getInitialState() = 0;
    virtual State* getGoalState() = 0;
    virtual list<State*> getAllPossibleStates(State s) = 0;
};


#endif //FINAL_PROJECT_SECOND_SEARCHABLE_H
