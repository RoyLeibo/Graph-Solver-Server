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

    unordered_map<string, State*> vertex_map ;
    string entry_vertex ;
    string exit_vertex ;

public:
    Matrix(vector<string> matrix_vec) ;
    string get_entry_vertex() ;
    string get_exit_vertex() ;

private:
    void build_matrix(vector<string> matrix_vec) ;
    vector<string> line_parse(string line) ;
    void update_map(vector<string> line_vec, int i) ;
};


#endif //FINAL_PROJECT_SECOND_MATRIX_H
