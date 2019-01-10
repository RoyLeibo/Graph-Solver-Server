//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_MATRIX_H
#define FINAL_PROJECT_SECOND_MATRIX_H

#include <iostream>
#include <cstddef>
#include <unordered_map>
#include <vector>
#include "State.h"
#include "Searchable.h"

using namespace std ;

class Matrix: public Searchable {

    unordered_map<string, State*> vertex_map ;
    State* entry_vertex ;
    State* exit_vertex ;
    int n ;

public:
    Matrix(vector<string> matrix_vec) ;
    virtual State* getInitialState() ;
    virtual State* getGoalState() ;
    int get_i(State s) ;
    int get_j(State s) ;
    string create_index(int i, int j) ;
    virtual list<State*> getAllPossibleStates(State s) ;

private:
    void build_matrix(vector<string> matrix_vec) ;
    vector<string> line_parse(string line) ;
    void update_map(vector<string> line_vec, int i) ;
};


#endif //FINAL_PROJECT_SECOND_MATRIX_H
