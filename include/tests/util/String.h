#pragma once
#include <vector>
#include <string>
#include <string_view>

namespace Tests::Util::String {
    std::vector<std::string> splitWords(const std::string_view &str, const std::string &delimiter);
}
