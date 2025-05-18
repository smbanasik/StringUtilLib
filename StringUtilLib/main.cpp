// Spencer Banasik
// Test bed
#include "string_util.h"

#include <iostream>

int main() {

    std::string test_one = "Hello, world!";

    std::string res_one = sb::stdstr::substr_it(test_one.begin(), test_one.end() - 5);

    std::cout << res_one << "\n";

    std::vector<std::string> res_two = sb::stdstr::split(test_one, ',');
    
    for (auto& elem : res_two)
        std::cout << elem << "\n";

    std::string res_three = sb::stdstr::join(res_two, '_');

    std::cout << res_three << "\n";

    return 0;
}