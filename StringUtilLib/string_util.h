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
constexpr int _LOWERCASE_MAX = 122;
constexpr int _LOWERCASE_MIN = 97;
constexpr int _UPPERCASE_MAX = 90;
constexpr int _UPPERCASE_MIN = 65;
constexpr int _UPPER_LOWER_DIFF = 32;

// Creates a substring using string iterators instead of positions
std::string substr_it(const std::string::const_iterator begin, const std::string::const_iterator end) {
    std::string dest;
    dest.resize(end - begin);
    std::copy(begin, end, dest.begin());
    return dest;
}

// Split a string into a vector of strings using a delimiter
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

// Joins a vector of strings together with a delimiter
std::string join(const std::vector<std::string>& input, const char delimiter) {

    std::string ret_val = input[0];

    for (auto it = input.begin() + 1; it != input.end(); it++) {
        ret_val += delimiter + *it;
    }

    return ret_val;
}

std::string to_upper(const std::string& input) {
    std::string ret_val;
    ret_val.reserve(input.size());

    auto dest = ret_val.begin();

    for (auto it = input.begin(); it != input.end(); it++, dest++) {
        *dest = *it;

        if (*dest <= _LOWERCASE_MAX && *dest >= _LOWERCASE_MIN) {
             *dest -= _UPPER_LOWER_DIFF;
        }
    }

    return ret_val;
}
std::string to_lower(const std::string& input) {
    std::string ret_val;
    ret_val.reserve(input.size());

    auto dest = ret_val.begin();

    for (auto it = input.begin(); it != input.end(); it++, dest++) {
        *dest = *it;

        if (*dest <= _UPPERCASE_MAX && *dest >= _UPPERCASE_MIN) {
            *dest += _UPPER_LOWER_DIFF;
        }
    }

    return ret_val;
}

// Returns false if uppercase characters found
bool is_lower(const std::string& input) {
    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it <= _UPPERCASE_MAX && *it >= _UPPERCASE_MIN) {
            return false;
        }
    }
    return true;
}

// Returns false if lowercase characters found
bool is_upper(const std::string& input) {
    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it <= _LOWERCASE_MAX && *it >= _LOWERCASE_MIN) {
            return false;
        }
    }
    return true;
}


}
}
#endif