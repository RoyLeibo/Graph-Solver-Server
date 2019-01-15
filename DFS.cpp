//
// Created by einat on 1/10/19.
//

#include "DFS.h"

/*
 * This function get searchable
 * and return possible way to goalState when the start is in initialState
 */
string DFS::search(Searchable* searchable)
{
    //create vertex map
    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    //create adjacent map
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map , searchable->get_n()) ;
    //create visited map
    map<string, bool> visited_map = SearchableUtility::create_visited_map(vertex_map) ;
    //use searchDFS in recursion to find the possible way to goalState from initialState
    searchDFS(adjacent_map,visited_map,searchable->getInitialState(),searchable->getGoalState());
    //restore the solution
    cout<< this->counter<<"\n"<<endl;
    return SearchableUtility::restore_solution(searchable);

}

/*
 * This function get adjacent map,visited map, state and goalStart
 * move on all vertex adjacent and do recursion
 * in each recursion the vertex get father
 */
 void DFS::searchDFS( map<string, vector<State*>>  adjacent_map,map<string, bool> visited_map , State* current, State* goalState)
 {
     //mark the vertex as visited
     visited_map[current->get_vertex_index()] = true;
     this->counter++;
     vector<State*> temp_adjacent = adjacent_map[current->get_vertex_index()] ;
     State* current_adjacent ;
     //move on all vertex adjacent
     for (int i = 0; i < temp_adjacent.size() ; i++)
     {
         current_adjacent = temp_adjacent[i] ;
         //if the state have not visited yet
         if(visited_map[current_adjacent->get_vertex_index()] == false) {
             //set the current vertex to be his father
             current_adjacent->set_father(current) ;
             //if it id not the goalState do recursion with current adjacent vertex
             if(current_adjacent != goalState) {
                 searchDFS(adjacent_map, visited_map, current_adjacent, goalState);
             }
             //if it id the goalState finish the function
             else
             {
                 break;
             }
         }
     }
 }

int DFS:: getNumberOfNodesEvaluated()
{
    return this->counter;
}

DFS::~DFS(){};

