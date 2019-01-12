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
    int n ;
    bool is_matrix_legal ;

public:
    Matrix(vector<string> vertex_map) ;
    virtual State* getInitialState() ;
    virtual State* getGoalState() ;
    virtual unordered_map<string, State*>* get_vertex_map() ;
    virtual int get_n() ;

private:
    bool build_matrix(vector<string> matrix_vec) ;
    vector<string> line_parse(string line) ;
    bool update_map(vector<string> line_vec, int i) ;
};


#endif //FINAL_PROJECT_SECOND_MATRIX_H
