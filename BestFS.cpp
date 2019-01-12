//
// Created by einat on 1/12/19.
//

#include "BestFS.h"
#include <algorithm>
string BestFS::search(Searchable* searchable)
{

    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map , searchable->get_n()) ;
    map<string, bool> visited_map = SearchableUtility::create_visited_map(vertex_map) ;
    map<string, double> cost_map = build_f_map(vertex_map);
    vector<State*> vec;
    vector<State *>::iterator current;
    State* current_adjacent ;
    vec.push_back(searchable->getInitialState());
    while(!vec.empty())
    {
        current = find_lowest_cost(&vec,&cost_map);
        vec.erase(current);
        if((*current) == searchable->getGoalState())
        {
            return SearchableUtility::restore_solution(searchable);
        }
        else
        {
            vector<State*> temp_adjacent = adjacent_map[(*current)->get_vertex_index()] ;
            for (int i = 0 ; i < temp_adjacent.size() ; i++) {
                current_adjacent = temp_adjacent[i];
                if(!visited_map[current_adjacent->get_vertex_index()]) {
                    current_adjacent->set_father(*current) ;
                    visited_map[current_adjacent->get_vertex_index()] = true;
                    if(current_adjacent == searchable->getGoalState())
                    {
                        return SearchableUtility::restore_solution( searchable);
                    }
                    vec.push_back(current_adjacent);
                }

            }
        }
    }
}

string BestFS::searchtwo(Searchable* searchable)
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


vector<State *>::iterator BestFS::find_lowest_cost(vector<State *> *vec, map<string, double> *cost_to_vertex_map) {
    int min_cost = numeric_limits<int>::max();
    vector<State *>::iterator it;
    vector<State *>::iterator min_cost_it;
    int temp_cost;
    for (it = vec->begin(); it != vec->end(); it++) {
        temp_cost = (*cost_to_vertex_map)[(*it)->get_vertex_index()];
        if (temp_cost < min_cost) {
            min_cost = temp_cost;
            min_cost_it = it;
        }
    }
    return min_cost_it;
}

map<string, double> BestFS::build_f_map(unordered_map<string, State *> *vertex_map) {
    int init_cost = numeric_limits<int>::max();
    map<string, double> g_map;
    unordered_map<string, State *>::iterator it;
    for (it = vertex_map->begin(); it != vertex_map->end(); ++it) {
        g_map.insert(pair<string, int>(it->first, init_cost));
    }
    return g_map;
}
