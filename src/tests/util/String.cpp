#include <tests/util/String.h>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> Tests::Util::String::splitWords(const std::string_view &str, const std::string &delimiter) {
    std::vector<std::string> words;
    size_t start = 0;

    while (start < str.size()) {
        size_t end = str.find(delimiter, start);
        if (end == std::string_view::npos) {
            end = str.size();
        }
        words.emplace_back(str.substr(start, end - start));
        start = end + delimiter.size();
    }

    return words;
}
