
#ifndef FINAL_PROJECT_SECOND_FILECACHMENGER_H
#define FINAL_PROJECT_SECOND_FILECACHMENGER_H

#include "CacheManager.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>


class FileCacheManager : public CacheManager<std::string,std::string> {
    private:
        std::unordered_map<std::string,std::string> hash_map;
        bool flg;
        std::vector<std::pair<std::string,std::string>> vec;
        std::fstream solution_file;
        void line_to_map(std::string line);
        void update_map();

    public:
        FileCacheManager();
        virtual bool find_solution(std::string problem);
        virtual std::string get_solution(std::string problem);
        void add_solution(std::pair<std::string,std::string> solution);
        virtual void write_to_file(std::vector<std::string> vec);
};


#endif //FINAL_PROJECT_SECOND_FILECACHMENGER_H
