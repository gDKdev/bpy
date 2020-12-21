#ifndef BPYTHON_TRIM_STRING_HPP
#define BPYTHON_TRIM_STRING_HPP

// Shamelessly stolen from Stack Overflow
// https://stackoverflow.com/a/217605

#include <algorithm>
#include <cctype>
#include <locale>

static inline auto lsIndex(std::string &s) {
    return std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace)));
}

// trim from start (copying)
static inline std::string ltrim(std::string s) {
    s.erase(s.begin(), lsIndex(s));
    return s;
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

#endif //BPYTHON_TRIM_STRING_HPP
