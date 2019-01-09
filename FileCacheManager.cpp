#include "FileCacheManager.h"

FileCacheManager::FileCacheManager()
{
    this->flg = false;
}

bool FileCacheManager:: find_solution(std::string problem)
{
    //check if the problem is in the map
    std::unordered_map<std::string,std::string> :: iterator it;
    it = this->hash_map.find(problem);
    //if yes return true
    if(it != this->hash_map.end())
    {
        return true;
    }
    //if not and the hash_map is update return false
    if(this->flg)
    {
       return false;
    }
    else
    {
        update_map();
        this->flg = true;
    }

}
std::string FileCacheManager:: get_solution(std::string problem)
{
    return this->hash_map[problem];
}

void FileCacheManager:: add_solution(std::pair<std::string,std::string> solution)
{
    this->vec.push_back(solution);
}

void FileCacheManager::update_map()
{
    std::string line;
    this->solution_file.open("solution_file.csv",std::ios::app);
    this->solution_file.close();
    while(getline(this->solution_file,line))
    {
        line_to_map(line);
    }

}

void FileCacheManager::line_to_map(std::string line)
{
    std::string key;
    std::string value;
    int mark_comma = 0;
    mark_comma = line.find(',',0);
    key = line.substr(0,mark_comma - 1);
    value = line.substr(mark_comma + 1, line.length() -1);
    this->hash_map[key] = value;

}

void FileCacheManager::write_to_file(std::vector<std::pair<std::string,std::string>> vec)
{
    std::string line;
    int len_vec = vec.size();
    this->solution_file.open("solution_file.csv",std::ios::app);
    for(int i = 0; i < len_vec; i++)
    {
        line = "";
        line = this->vec.at(i).first + ',' + this->vec.at(i).second;
        this->solution_file << line << std::endl;
    }
}
FileCacheManager::~FileCacheManager()
{
    write_to_file(this->vec);
}