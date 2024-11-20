#pragma once
#include <vector>
#include <string>
#include <string_view>

namespace Common::Util::String {
    std::vector<std::string> splitWords(const std::string_view &str, const std::string& delimiter);
    std::vector<std::string> parseVectorString(const std::string &str);
    std::vector<int> parseVectorInt(const std::string &str);
    std::vector<std::vector<std::string>> parse2DVectorString(const std::string &str);
    std::vector<std::vector<int>> parse2DVectorInt(const std::string &str);
    std::vector<std::vector<char>> parse2DVectorChar(const std::string &str);
}
