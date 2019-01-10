//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_SEARCHABLEUTILITY_H
#define FINAL_PROJECT_SECOND_SEARCHABLEUTILITY_H

#include <unordered_map>
#include <vector>
#include <map>
#include <string>
#include "State.h"

using namespace std ;

class SearchableUtility {

public:
    static vector<State*> getAllPossibleStates(State* s, unordered_map<string, State*>* vertex_map, int n) ;
    static map<string, vector<State*>>build_adjacent_map(unordered_map<string, State*>* vertex_map, int n) ;
    static map<string, bool> create_visited_map(unordered_map<string, State*>* vertex_map) ;
    static void set_visited_map(string index, map<string, bool>* visited_map) ;
    static string create_index(int i, int j) ;

};


#endif //FINAL_PROJECT_SECOND_SEARCHABLEUTILITY_H
