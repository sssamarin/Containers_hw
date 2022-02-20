#include <iostream>
#include "timer_class.h"

template<typename T>
void show_data(T Map){
    for (const auto& [key, value] : Map) {
        std::cout  << key << " || " << value << std::endl;
    }
    std::cout << std::endl;
};

void pull_random_user(std::multimap<std::string, std::string> Map){
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    int z = Map.size();
//    std::cout << typeid(z).name()   << std::endl;
    auto distribution = std::uniform_int_distribution(0, z - 1);
    auto user_finder_iterator = std::next(std::begin(Map), distribution(generator));
    std::cout << user_finder_iterator->first << " || " << user_finder_iterator->second << std::endl;
    std::cout << std::endl;
};

void search_by_surname(std::multimap<std::string, std::string> Map, std::string Surname){
    std::cout << Map.find(Surname)->first << " || " << Map.find(Surname)->second << std::endl;
    std::cout << std::endl;
};

int main() {
    std::multimap<std::string, std::string> Telephone_dict  {{"Samarin",   "89686317143"},
                                                             {"Samarin", "89689388863"},
                                                             {"Popov", "89161408465"},
                                                             {"Titov", "89121337803"},
                                                             {"Ivanov", "9969951337202"}};
    show_data(Telephone_dict);
    pull_random_user(Telephone_dict);
    search_by_surname(Telephone_dict, "Samarin");

    return 0;
}