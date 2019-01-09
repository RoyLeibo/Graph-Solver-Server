//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_MATRIX_H
#define FINAL_PROJECT_SECOND_MATRIX_H

#include <iostream>
#include <cstddef>
using namespace std ;


class Matrix {

    int *matrix ;
    int n ;

public:
    Matrix(int n) ;
    size_t find_index(int x, int y) ;

};


#endif //FINAL_PROJECT_SECOND_MATRIX_H
