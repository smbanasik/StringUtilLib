# StringUtilLib

This is a simple library containing some utility functions that I believe std::string should have. Python and Java have a variety of useful string functions, such as split and join, that I did not see for C++. Additionally, string functions lack functionality that should be expected within the library, such as substr not working with iterators [1](https://en.cppreference.com/w/cpp/string/basic_string/substr), or erase not working with reverse iterators [2](https://stackoverflow.com/questions/1830158/how-to-call-erase-with-a-reverse-iterator)[3](https://en.cppreference.com/w/cpp/string/basic_string/erase).

Some functionality in the library, like to_upper and to_lower is able to be performed with std::transform, but I believe that to be less intuitive than specific functions.

## Usage

Place 'string_util.h' into your directory and #include it. You will find these functions under the sb::stdstr namespace. Refer to the file for documentation on the functions.

## Future Work

The library should move towards stringviews and spans instead of the actual datatypes.

I am considering making the interface more lower level, or to have lower level options that focus more on character strings and basic arrays.

Work could be done to allow for mutli-character delimiters for split and join.

Regex functionality for string searching is nice, but I intend on making my own regex parser first.

More functions could be added that do more interesting things with strings (title case, snake case, reversing a string, finding palindromes, etc.), I will add these as I see a need for it.