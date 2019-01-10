//
// Created by royl8 on 1/10/19.
//

#include "AStar.h"

string AStar::search(Searchable* searchable) {
    queue<State*> q ;
    map<string, int> cost_to_vertex_map ;
    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map, searchable->get_n()) ;
    map<string, bool> visited_map = SearchableUtility::create_visited_map(vertex_map) ;
}
