#include "str_util.h"

namespace utils {

    std::vector<std::string> split(const std::string& str, const char* delim) {
        std::vector<std::string> v;
        std::string tmp;

        for (auto i = str.begin(); i != str.end(); ++i) {
            if (*i != *delim && i != str.end()) {
                tmp += *i;
            }
            else {
                v.emplace_back(tmp);
                tmp = "";
            }
        }
        return v;
    }

    std::vector<uint32_t> split2Int(const std::string& str, const char* delim) {
        std::vector<uint32_t> v;
        std::string tmp;

        for (auto i = str.begin(); i != str.end(); ++i) {
            if (*i != *delim && i != str.end()) {
                tmp += *i;
            }
            else {
                v.push_back(strtoul(tmp.c_str(), nullptr, 10));
                tmp = "";
            }
        }
        return v;
    }
}