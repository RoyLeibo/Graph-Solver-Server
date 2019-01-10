//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_MATRIX_H
#define FINAL_PROJECT_SECOND_MATRIX_H

#include <iostream>
#include <cstddef>
#include <unordered_map>
#include <vector>
#include <map>
#include "State.h"
#include "Searchable.h"

using namespace std ;

class Matrix: public Searchable {

    unordered_map<string, State*> vertex_map ;
    State* entry_vertex ;
    State* exit_vertex ;
    map<string, bool> visited_map ;
    int n ;

public:
    Matrix(vector<string> matrix_vec) ;
    virtual State* getInitialState() ;
    virtual State* getGoalState() ;
    string create_index(int i, int j) ;
    map<string, vector<State*>>build_adjacent_map() ;
    map<string, bool> create_visited_map() ;
    virtual vector<State*> getAllPossibleStates(State* s) ;
    void set_visited_map(string index) ;


private:
    void build_matrix(vector<string> matrix_vec) ;
    vector<string> line_parse(string line) ;
    void update_map(vector<string> line_vec, int i) ;
};


#endif //FINAL_PROJECT_SECOND_MATRIX_H
