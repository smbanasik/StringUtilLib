// Spencer Banasik
// StringUtilLib
// A set of header only functions that provide additional utility to C++ strings
// Since these deal with higher level abstractions, I have avoided using
// lower level arrays or functions at the cost of memory or performance.
#ifndef SB_STRING_UTIL_H
#define SB_STRING_UTIL_H
#include <string>
#include <vector>
#include <algorithm>

namespace sb {

namespace stdstr {

std::string substr_it(const std::string::const_iterator begin, const std::string::const_iterator end) {
    std::string dest;
    dest.resize(end - begin);
    std::copy(begin, end, dest.begin());
    return dest;
}

std::vector<std::string> split(const std::string& input, const char delimiter) {

    std::vector<std::string> ret_val;
    auto last_char = input.begin();
    
    for (auto it = input.begin(); it != input.end(); it++) {
    
        if (*it == delimiter) {
            ret_val.push_back(substr_it(last_char, it));
            last_char = it + 1;
        }
    }
    
    if (last_char != input.end()) {
        ret_val.push_back(substr_it(last_char, input.end()));
    }
    return ret_val;
}

std::string join(const std::vector<std::string>& input) {

    

    return "";
}


}
}
#endif