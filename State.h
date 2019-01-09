//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_STATE_H
#define FINAL_PROJECT_SECOND_STATE_H

#include <string>
#include <iostream>

using namespace std ;


class State {

    State* father ;
    pair<int, int> vertex_index ;
    int cost ;

public:
    State(pair<int, int> vertex_index, int cost) ;
    State* get_father() ;
    pair<int, int> get_vertex() ;
    int get_cost() ;
    void set_father (State* father) ;
    void set_vertex(pair<int, int> vertex) ;
    void set_cost(int cost) ;

};


#endif //FINAL_PROJECT_SECOND_STATE_H
