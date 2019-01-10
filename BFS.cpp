//
// Created by royl8 on 1/10/19.
//

#include "BFS.h"

string BFS::search(Searchable* searchable) {
    queue<State*> q ;
    map<string, vector<State*>> adjacent_map = searchable->build_adjacent_map() ;
    map<string, bool> visited_map = searchable->create_visited_map() ;
    q.push(searchable->getInitialState()) ;
    searchable->set_visited_map(searchable->getInitialState()->get_vertex_index()) ;
    State* vertex ;
    State* adjacent ;
    while(q.empty() == false) {
        vertex = q.front() ;
        q.pop() ;
        vector<State*> temp_adjacent = adjacent_map[vertex->get_vertex_index()] ;
        for (int i = 0 ; i < temp_adjacent.size() ; i++) {
            adjacent = temp_adjacent[i] ;
            if(visited_map[adjacent->get_vertex_index()] == false) {
                adjacent->set_father(vertex) ;
                if(adjacent != searchable->getGoalState()) {
                    q.push(adjacent);
                    visited_map[adjacent->get_vertex_index()] = true;
                }
                else {
                    return restore_solution(searchable) ;
                }
            }
        }
    }
}

string BFS::restore_solution(Searchable* searchable) {
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

string BFS::check_direction(State* current) {
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

int BFS::getNumberOfNodesEvaluated() {

}