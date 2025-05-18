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

/**
 * @brief Checks if a character is whitespace
 * @author Spencer Banasik
 * @param[in] input  The character being tested.
 *
 * @return A boolean value of whether the character is whitespace or not.
 */
bool is_char_whitespace(char input) {

    return (input == ' ' || input == '\n' || input == '\t');
}

/**
 * @brief Creates a substring from two string iterators. [begin,end)
 * @author Spencer Banasik
 * @param[in] begin  The starting point to copy the string.
 * @param[in] end    The end point to copy the string, not explicitly included.
 *
 * @return A substring made from all characters between the two iterators.
 *
 * @note This function assumes the two iterators are from the same string and that there are characters between them.
 */
std::string substr_it(const std::string::const_iterator begin, const std::string::const_iterator end) {

    std::string dest;
    dest.resize(end - begin);
    std::copy(begin, end, dest.begin());
    return dest;
}

/**
 * @brief Splits a string into a vector of strings using a delimiter
 * @author Spencer Banasik
 * @param[in] input      The string to be split.
 * @param[in] delimiter  The character used to deliminate the substrings.
 *
 * @return A vector of strings split from the original.
 */
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

/**
 * @brief Creates a string from a vector of strings which are joined together by a delimiter.
 * @author Spencer Banasik
 * @param[in] input      The vector of strings to be joined.
 * @param[in] delimiter  The character used to join together the input.
 *
 * @return A string of the vector elements joined together by the delimiter character.
 */
std::string join(const std::vector<std::string>& input, const char delimiter) {

    std::string ret_val = input[0];
    for (auto it = input.begin() + 1; it != input.end(); it++) {
        ret_val += delimiter + *it;
    }

    return ret_val;
}

/**
 * @brief Converts a string to uppercase.
 * @author Spencer Banasik
 * @param[in] input  The string to be converted to uppercase.
 *
 * @return The string, now in uppercase.
 */
std::string to_upper(std::string input) {

    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it <= _LOWERCASE_MAX && *it >= _LOWERCASE_MIN) {
             *it -= _UPPER_LOWER_DIFF;
        }
    }

    return input;
}
/**
 * @brief Converts a string to lowercase.
 * @author Spencer Banasik
 * @param[in] input  The string to be converted to lowercase.
 *
 * @return The string, now in lowercase.
 */
std::string to_lower(std::string input) {

    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it <= _UPPERCASE_MAX && *it >= _UPPERCASE_MIN) {
            *it += _UPPER_LOWER_DIFF;
        }
    }

    return input;
}

/**
 * @brief Checks if a string has uppercase characters.
 * @author Spencer Banasik
 * @param[in] input  The string to be checked.
 *
 * @return Returns false if the string has uppercase characters, true otherwise.
 */
bool is_lower(const std::string& input) {

    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it <= _UPPERCASE_MAX && *it >= _UPPERCASE_MIN) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Checks if a string has lowercase characters.
 * @author Spencer Banasik
 * @param[in] input  The string to be checked.
 *
 * @return Returns false if the string has lowercase characters, true otherwise.
 */
bool is_upper(const std::string& input) {

    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it <= _LOWERCASE_MAX && *it >= _LOWERCASE_MIN) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Trims any whitespace to the right of the string.
 * @author Spencer Banasik
 * @param[in] input The string to be trimmed.
 *
 * @return The trimmed string.
 */
std::string trim_right(std::string input) {

    // We cannot use iterators here because reverse erase has no reverse iteratior overload!
    for (int i = input.size() - 1; i >= 0; i--) {
        if (is_char_whitespace(input[i])) {
            input.erase(i, 1);
        }
        else {
            break;
        }
    }
    return input;
}

/**
 * @brief Trims any whitespace to the left of the string.
 * @author Spencer Banasik
 * @param[in] input The string to be trimmed.
 *
 * @return The trimmed string.
 */
std::string trim_left(std::string input) {

    for (int i = 0; i < input.size();) {
        if (is_char_whitespace(input[i])) {
            input.erase(0, 1);
        }
        else {
            break;
        }
    }

    return input;
}

/**
 * @brief Trims any whitespace to the left and right of the string.
 * @author Spencer Banasik
 * @param[in] input The string to be trimmed.
 *
 * @return The trimmed string.
 */
std::string trim(std::string input) {

    input = trim_right(input);
    return trim_left(input);
}


}
}
#endif
