//
// Created by einat on 1/10/19.
//

#include "DFS.h"

string DFS::search(Searchable* searchable)
{
    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map , searchable->get_n()) ;
    map<string, bool> visited_map = SearchableUtility::create_visited_map(vertex_map) ;
    searchDFS(adjacent_map,visited_map,searchable->getInitialState(),searchable->getGoalState());
    return SearchableUtility::restore_solution(searchable);

}
 void DFS::searchDFS( map<string, vector<State*>>  adjacent_map,map<string, bool> visited_map , State* current, State* goalState)
 {
     visited_map[current->get_vertex_index()] = true;
     vector<State*> temp_adjacent = adjacent_map[current->get_vertex_index()] ;
     State* current_adjacent ;
     for (int i = 0; i < temp_adjacent.size() ; i++)
     {
         current_adjacent = temp_adjacent[i] ;
         if(current_adjacent->get_cost() < 0)
         {
             visited_map[current_adjacent->get_vertex_index()] = true;
         }
         if(visited_map[current_adjacent->get_vertex_index()] == false) {
             current_adjacent->set_father(current) ;
             if(current_adjacent != goalState) {
                 searchDFS(adjacent_map, visited_map, current_adjacent, goalState);
             }
             else
             {
                 break;
             }
         }
     }
 }

