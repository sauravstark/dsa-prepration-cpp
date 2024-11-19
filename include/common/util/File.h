#pragma once
#include <vector>
#include <string>

namespace Common::Util::File {
    std::vector<std::string> readLinesFromFile(const std::string& filename);
}
