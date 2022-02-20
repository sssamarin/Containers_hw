#include <iostream>
#include "timer_class.h"

int main() {
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution(-100, 100);

    std::vector<int> Vector;
    std::generate_n(std::back_inserter(Vector), 100000,
                    [&distribution, &generator](){return distribution(generator);});
//    std::cout << Vector << std::endl;

    std::array<int, 100000> Array;
    std::generate_n(std::begin(Array), 100000,
                    [&distribution, &generator](){return distribution(generator);});

    std::deque<int> Deque;
    std::generate_n(std::back_inserter(Deque), 100000,
                    [&distribution, &generator](){return distribution(generator);});

    std::list<int> List;
    std::generate_n(std::back_inserter(List), 100000,
                    [&distribution, &generator](){return distribution(generator);});
    List.push_back('other type data');

    std::forward_list<int> Forward_list;
    std::generate_n(std::front_inserter(Forward_list), 100000,
                    [&distribution, &generator](){return distribution(generator);});
    List.push_back('other type data');

    Timer<microseconds> t1;
    std::sort(std::begin(Vector),std::end(Vector));
    t1.Pause(); std::cout << " (Vector)" << std::endl;
    t1.Start();

    std::sort(std::begin(Array),std::end(Array));
    t1.Pause(); std::cout << " (Array)" << std::endl;
    t1.Start();

    std::sort(std::begin(Deque),std::end(Deque));
    t1.Pause(); std::cout << " (Deque)" << std::endl;
    t1.Start();

    List.sort();
    t1.Pause(); std::cout << " (List)" << std::endl;
    t1.Start();

    Forward_list.sort();
    t1.Pause(); std::cout << " (Forward list)" << std::endl;
    t1.Start();

    std::cout << "Absolute winner is Array" << std::endl;

    return 0;
}
