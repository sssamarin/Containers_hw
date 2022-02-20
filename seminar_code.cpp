#include <iostream>
#include <vector>
#include <list>

struct Fraction {
    Fraction(int numerator, unsigned int denominator) :
            numerator(numerator), denominator(denominator) {}

    int numerator;
    unsigned denominator;
};

int main() {
//    std::cout << "Hello, DPQE!" << std::endl;
//    std::vector<int> subject;
//    for(auto i = 0; i < 30; i++) {
//        subject.push_back(i);
//        std::cout << "Size is " << subject.size()
//            << ", capacity is " << subject.capacity() << std::endl;
//    }

//    std::vector<Fraction> fractions;
//    fractions.emplace_back(1, 2);

    std::list<int> numbers{1, 5, 42, 255, -34, 0};
    std::list<int> other_numbers{32, -6464, 128, 5};
//    numbers.splice(std::next(numbers.begin(), 2), other_numbers,
//                   std::next(std::begin(other_numbers)),
//                   std::prev(std::end(other_numbers)));
//    for(auto number: numbers) {
//        std::cout << number << ' ';
//    }
//    std::cout << std::endl;
//    for(auto number: other_numbers) {
//        std::cout << number << ' ';
//    }
//    std::cout << std::endl;
    numbers.sort();
    other_numbers.sort([](auto lhs, auto rhs) {
        return std::abs(lhs) < std::abs(rhs);
    });
    for(auto number: numbers) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
    for(auto number: other_numbers) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
    numbers.merge(other_numbers);
    for(auto number: numbers) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
    return 0;
}

