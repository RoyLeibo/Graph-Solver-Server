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

using namespace std ;

class Matrix {

    unordered_map<pair<int, int>, State*> vertex_map ;
    pair<int, int> entry_vertex ;
    pair<int, int> exit_vertex ;

public:
    Matrix(vector<string> matrix_vec) ;
    void build_matrix(vector<string> matrix_vec) ;
    vector<string> line_parse(string line) ;
    void update_map(vector<string> line_vec, int i) ;
    pair<int, int> get_entry_vertex() ;
    pair<int, int> get_exit_vertex() ;
};


#endif //FINAL_PROJECT_SECOND_MATRIX_H
