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
    string vertex_index ;
    double cost ;

public:
    State(string vertex_index, double cost) ;
    State* get_father() ;
    string get_vertex_index() ;
    double get_cost() ;
    void set_father (State* father) ;
    void set_vertex(string vertex) ;
    void set_cost(double cost) ;
    int get_i() ;
    int get_j();

};


#endif //FINAL_PROJECT_SECOND_STATE_H
