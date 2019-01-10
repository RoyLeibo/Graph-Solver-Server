//
// Created by royl8 on 1/10/19.
//

#include "AStar.h"

string AStar::search(Searchable* searchable) {
    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    map<string, int> cost_to_vertex_map = build_path_cost_map(vertex_map) ;
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map, searchable->get_n()) ;

    vector<State*> open_vec ;
    vector<State*> close_vec ;
    open_vec.push_back(searchable->getInitialState()) ;

    State* current_vertex ;
    State* temp_adj ;

    vector<State*> current_adjancents ;
    vector<State*>::iterator it ;

    while(open_vec.empty() == false) {
        current_vertex = open_vec.front() ;
        it = open_vec.begin() ;
        if(current_vertex != searchable->getGoalState()) {
            open_vec.erase(it) ;
            close_vec.push_back(current_vertex);
            current_adjancents = adjacent_map.at(current_vertex->get_vertex_index()) ;
            for(int i = 0 ; i < current_adjancents.size() ; i++) {
                temp_adj = current_adjancents[i] ;
                if (find_in_vec(&close_vec, temp_adj)) {
                    continue ;
                }
                else if(find_in_vec(&open_vec, temp_adj) ||
                (temp_adj->get_cost() < cost_to_vertex_map[temp_adj->get_vertex_index()])){

                }
            }
        }
        else {
            return restore_solution(searchable);
        }
    }

}

map<string, int> AStar::build_path_cost_map(unordered_map<string, State*>* vertex_map) {
    map<string, int> cost_to_vertex_map ;
    unordered_map<string, State*>::iterator it ;
    for(it = vertex_map->begin() ; it != vertex_map->end() ; ++it) {
        cost_to_vertex_map.insert(pair<string, int>(it->first, it->second->get_cost())) ;
    }
}

int AStar::heuristic_func(State* current, State* next_vertex, State* goal, map<string, int>* cost_to_vertex_map) {
    string next_vertex_id = next_vertex->get_vertex_index() ;
    int next_vertex_cost = cost_to_vertex_map->at(current->get_vertex_index()) +
            cost_to_vertex_map->at(next_vertex_id) + next_vertex->find_manhattan_distance(goal) ;
    (*cost_to_vertex_map)[next_vertex_id] = next_vertex_cost ;
    return next_vertex_cost ;
}

string AStar::restore_solution(Searchable* searchable) {
    State* current = searchable->getGoalState() ;
    vector<string> directions ;
    string answer = "{ " ;
    while(current != searchable->getInitialState()) {
        directions.push_back(check_direction(current)) ;
        current = current->get_father() ;
    }
    for(int i = directions.size()-1 ; i >= 0 ; i--) {
        answer += directions.at(i) + ", " ;
    }
    answer.erase(answer.length()-2, 2) ;
    answer += " }" ;
    return answer ;
}

string AStar::check_direction(State* current) {
    int current_i = current->get_i() ;
    int current_j = current->get_j() ;
    int father_i = current->get_father()->get_i() ;
    int father_j = current->get_father()->get_j() ;

    if (current_j == father_j) {
        if (current_i > father_i) {
            return "DOWN" ;
        }
        else {
            return "UP" ;
        }
    }
    else if (current_i == father_i) {
        if (current_j > father_j) {
            return "RIGHT" ;
        }
        else {
            return "LEFT" ;
        }
    }
}

bool AStar::find_in_vec(vector<State*>* vec, State* current) {
    string current_index = current->get_vertex_index() ;
    string temp_index ;
    for (int i = 0 ; i < vec->size() ; i++) {
        temp_index = (*vec)[i]->get_vertex_index() ;
        if (current_index == temp_index) {
            return true ;
        }
    }
    return false ;
}

int AStar::find_lowest_cost(vector<State*>* vec, map<string,int>* cost_to_vertex_map) {
    int min_cost = numeric_limits<int>::max() ;
    int min_cost_index ;
    int temp_cost ;
    for (int i = 0 ; i < vec->size() ; i++) {
        temp_cost = (*cost_to_vertex_map)[(*vec)[i]->get_vertex_index()] ;
        if (temp_cost < min_cost) {
            min_cost = temp_cost ;
            min_cost_index = i ;
        }
    }
    return min_cost_index ;
}