//
// Created by royl8 on 1/9/19.
//

#include "Matrix.h"

Matrix::Matrix(vector<string> matrix_vec) {
    build_matrix(matrix_vec);
}

void Matrix::build_matrix(vector<string> matrix_vec) {
    int vec_size = matrix_vec.size() - 2;
    vector<string> line_vec;
    this->n = vec_size ;
    for (int i = 0; i < vec_size; i++) {
        line_vec = line_parse(matrix_vec.at(i));
        update_map(line_vec, i);
    }
    line_vec = line_parse(matrix_vec.at(vec_size));
    entry_vertex = vertex_map[line_vec.at(0) + "," + line_vec.at(1)];
    line_vec = line_parse(matrix_vec.at(++vec_size));
    exit_vertex = vertex_map[line_vec.at(0) + "," + line_vec.at(1)];
}

vector<string> Matrix::line_parse(string line) {
    int start_of_num = 0;
    int end_of_num;
    vector<string> line_vec;
    if (line[line.length() - 1] != ',') {
        line += ",";
    }
    while (true) {
        end_of_num = line.find(',', start_of_num);
        if (end_of_num != -1) {
            line_vec.push_back(line.substr(start_of_num, end_of_num - start_of_num));
            start_of_num = end_of_num + 1;
        } else {
            return line_vec;
        }
    }
}

void Matrix::update_map(vector<string> line_vec, int i) {
    int vec_length = line_vec.size();
    State *temp_state;
    string vertex_index;
    for (int j = 0; j < vec_length; j++) {
        vertex_index = to_string(i) + "," + to_string(j);
        temp_state = new State(vertex_index, stod(line_vec.at(j)));
        vertex_map.insert(pair<string, State *>(vertex_index, temp_state));
    }
}

State *Matrix::getInitialState() {
    return this->entry_vertex;
}

State *Matrix::getGoalState() {
    return this->exit_vertex;
}

int Matrix::get_i(State s) {
    string index = s.get_vertex_index() ;
    return stoi(index.substr(0, index.find(',', 0))) ;
}

int Matrix::get_j(State s) {
    string index_vertex = s.get_vertex_index() ;
    int index_of_comma = index_vertex.find(',', 0) ;
    return stoi(index_vertex.substr(index_of_comma+1, index_vertex.length()-index_of_comma-1)) ;
}

string Matrix::create_index(int i, int j) {
    return to_string(i)+","+to_string(j) ;
}

list<State*> Matrix::getAllPossibleStates(State s) {
    list<State*> possibleStates;
    int this_i = get_i(s) ;
    int this_j = get_j(s) ;
    if(this_i+1 < n) {
        possibleStates.push_front(vertex_map[create_index(this_i+1, this_j)]) ;
    }
    if(this_i-1 < 0) {
        possibleStates.push_front(vertex_map[create_index(this_i-1, this_j)]) ;
    }
    if(this_j+1 < n) {
        possibleStates.push_front(vertex_map[create_index(this_i, this_j+1)]) ;
    }
    if(this_j-1 < 0) {
        possibleStates.push_front(vertex_map[create_index(this_i, this_j-1)]) ;
    }
    return possibleStates;
}