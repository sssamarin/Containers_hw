#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>

#include <chrono>
#include <cmath>
#include <stdio.h>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <map>

using namespace std::chrono;
#ifndef WAT_TIMER_CLASS_H
#define WAT_TIMER_CLASS_H

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
    std::copy(std::begin(vector), std::end(vector),
              std::ostream_iterator<T>(out, " "));
    return out ;
}


template<typename T>
class Timer{
public:
    Timer(): start(steady_clock::now()), time(0)  {}
    ~Timer() {}
    void Pause(){
        time = steady_clock::duration(steady_clock::now() - start);
        std::cout << "Current process duration is " << duration_cast<T>(time).count() ;
    }
    void Start(){
        start = steady_clock::now();
    }
private:
    steady_clock::time_point start;
    steady_clock::duration time;
};


#endif //WAT_TIMER_CLASS_H
