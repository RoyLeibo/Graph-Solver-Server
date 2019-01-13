//
// Created by einat on 1/12/19.
//
#include "BestFS.h"
#include <algorithm>
#define  ONE 1
/*
 *This function get a searchable add return the shortest way
 * from the initialState to the goalState
 */
string BestFS::search(Searchable* searchable)
{
    //create vertex map
    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    //create adjacent map
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map , searchable->get_n()) ;
    //create visited map
    map<string, bool> visited_map = SearchableUtility::create_visited_map(vertex_map) ;
    //create cost map
    map<string, double> cost_map = build_f_map(vertex_map);
    vector<State*> vec;
    vector<State *>::iterator current;
    State* current_adjacent ;
    State* current_vertex;
    //push the initial state to the vector
    vec.push_back(searchable->getInitialState());
    while(!vec.empty())
    {
        //find the state with the lowest cost
        current = find_lowest_cost(&vec,&cost_map);
        current_vertex = *current;
        //erase the this state from the vector
        vec.erase(current);
        //if the state is the goal restore the solution
        if((current_vertex) == searchable->getGoalState())
        {
            return SearchableUtility::restore_solution(searchable);
        }
        else
        {
            //move on all the adjacent of the state
            vector<State*> temp_adjacent = adjacent_map[(current_vertex)->get_vertex_index()] ;
            for (int i = 0 ; i < temp_adjacent.size() ; i++) {
                current_adjacent = temp_adjacent[i];
                //if the state have not visited yet
                if(!visited_map[current_adjacent->get_vertex_index()]) {
                    //set the state father
                    current_adjacent->set_father(current_vertex);
                    //mark him as visited
                    visited_map[current_adjacent->get_vertex_index()] = true;
                    //check if he is the state gol
                    if(current_adjacent == searchable->getGoalState())
                    {
                        return SearchableUtility::restore_solution( searchable);
                    }
                    //push the state to vector
                    vec.push_back(current_adjacent);
                }
            }
        }
    }
}

/*string BestFS::searchtwo(Searchable* searchable)
{
    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map , searchable->get_n()) ;
    map<string, bool> visited_map = SearchableUtility::create_visited_map(vertex_map) ;
    map<string, double> cost_map = build_f_map(vertex_map);
    vector<State*> open;
    vector<State*> close;
    vector<State *>::iterator current;
    bool bool_close = false;
    bool bool_open = false;
    State* current_adjacent ;
    open.push_back(searchable->getInitialState());
    while(!open.empty())
    {
        current = find_lowest_cost(&open,&cost_map);
        close.push_back((*current));
        open.erase(current);
        if((*current) == searchable->getGoalState())
        {

        }
        else
        {
            vector<State*> temp_adjacent = adjacent_map[(*current)->get_vertex_index()] ;
            for (int i = 0 ; i < temp_adjacent.size() ; i++) {
                current_adjacent = temp_adjacent[i];
                bool_open = find_in_vec(&open,current_adjacent);
                bool_close = find_in_vec(&close,current_adjacent);
                if(!bool_open && !bool_open)
                {
                    current_adjacent->set_father(*current) ;
                    open.push_back(current_adjacent);
                }

            }
        }

    }
}

bool BestFS::find_in_vec(vector<State*> *vec,State* is_find)
{
    if(std::find((*vec).begin(),(*vec).end(),is_find) != (*vec).end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/

/*
 *This function get vector and map of costs
 * move on the vector and find the lowst cost
 */
vector<State *>::iterator BestFS::find_lowest_cost(vector<State *> *vec, map<string, double> *cost_to_vertex_map) {
    //it is iterator to the first organ in the vector
    vector<State *>::iterator it = vec->begin();
    vector<State *>::iterator min_cost_it;
    //min cost is one more than the first organ in order to get in to the if in the loop
    double min_cost = (*cost_to_vertex_map)[(*it)->get_vertex_index()]+ ONE;
    double temp_cost;
    //move on the organs in the vector
    for (it = vec->begin(); it != vec->end(); it++) {
        temp_cost = (*cost_to_vertex_map)[(*it)->get_vertex_index()];
        //if there is organ that have lower cost then the min cost save his value in min_cost
        if (temp_cost < min_cost) {
            min_cost = temp_cost;
            min_cost_it = it;
        }
    }
    return min_cost_it;
}
/*
 *This function get vertex map
 * move on the map and create map of cost
 */
map<string, double> BestFS::build_f_map(unordered_map<string, State *> *vertex_map) {
    map<string, double> c_map;
    unordered_map<string, State *>::iterator it;
    //move on the map and set the cost of every vertex in another map
    for (it = vertex_map->begin(); it != vertex_map->end(); ++it) {
        c_map.insert(pair<string, double >(it->first, it->second->get_cost()));
    }
    return c_map;
}
