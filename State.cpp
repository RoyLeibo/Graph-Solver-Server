//
// Created by royl8 on 1/9/19.
//

#include "State.h"

State::State(string vertex_index, int cost) {
    this->father = NULL ;
    this->vertex_index = vertex_index ;
    this->cost = cost ;
}

State* State::get_father() {
    return this->father ;
}

string State::get_vertex() {
    return this->vertex_index ;
}

int State::get_cost() {
    return this ->cost ;
}

void State::set_father(State* father) {
    this->father = father ;
}

void State::set_vertex(string vertex) {
    this->vertex_index = vertex ;
}

void State::set_cost(int cost) {
    this->cost = cost ;
}