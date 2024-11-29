#pragma once
#include <vector>
#include <string>

namespace Tests::Util::File {
    std::vector<std::string> readLinesFromFile(const std::string& filename);
}
