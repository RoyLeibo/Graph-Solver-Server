//
// Created by royl8 on 1/10/19.
//

#include "SearchableUtility.h"

vector<State*> SearchableUtility::getAllPossibleStates(State* s, unordered_map<string, State*>* vertex_map, int n) {
    vector<State*> possibleStates;
    int this_i = s->get_i() ;
    int this_j = s->get_j() ;
    if(this_i+1 < n) {
        possibleStates.push_back(vertex_map->at(create_index(this_i+1, this_j))) ;
    }
    if(this_i-1 >= 0) {
        possibleStates.push_back(vertex_map->at(create_index(this_i-1, this_j))) ;
    }
    if(this_j+1 < n) {
        possibleStates.push_back(vertex_map->at(create_index(this_i, this_j+1))) ;
    }
    if(this_j-1 >= 0) {
        possibleStates.push_back(vertex_map->at(create_index(this_i, this_j-1))) ;
    }
    return possibleStates;
}

map<string, vector<State*>>SearchableUtility::build_adjacent_map(unordered_map<string, State*>* vertex_map, int n) {
    map<string, vector<State*>> adjacent_map ;
    unordered_map<string, State*>::iterator it ;
    for(it = vertex_map->begin() ; it != vertex_map->end() ; it++) {
        adjacent_map[it->first] = getAllPossibleStates(it->second, vertex_map, n) ;
    }
    return adjacent_map ;
}

map<string, bool> SearchableUtility::create_visited_map(unordered_map<string, State*>* vertex_map) {
    unordered_map<string, State*>::iterator it ;
    map<string, bool> visited_map ;
    for(it = vertex_map->begin() ; it != vertex_map->end() ; it++) {
        visited_map.insert(pair<string, bool>(it->first, false)) ;
    }
    return visited_map ;
}

void SearchableUtility::set_visited_map(string index, map<string, bool>* visited_map) {
    visited_map->at(index) = true ;
}

string SearchableUtility::create_index(int i, int j) {
    return to_string(i)+","+to_string(j) ;
}
