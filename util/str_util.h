#pragma once
#include <string>
#include <vector>

namespace utils {
    std::vector<std::string> split(const std::string& str, const char* delim);

    std::vector<uint32_t> split2Int(const std::string& str, const char* delim);
}
