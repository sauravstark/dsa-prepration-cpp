#include <common/util/String.h>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> Common::Util::String::splitWords(const std::string_view &str, const std::string &delimiter) {
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

std::vector<std::string> Common::Util::String::parseVectorString(const std::string &str) {
    if (str.size() < 2)
        throw std::invalid_argument("Not enough bytes provided: " + str);

    if (str.front() != '[' || str.back() != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    return splitWords(std::string_view(str.data() + 1, str.size() - 2), ",");
}

std::vector<int> Common::Util::String::parseVectorInt(const std::string &str) {
    const auto words = parseVectorString(str);
    std::vector<int> result(words.size());
    std::ranges::transform(words, result.begin(), [](const auto &word) { return std::stoi(word); });
    return result;
}

std::vector<std::vector<std::string> > Common::Util::String::parse2DVectorString(const std::string &str) {
    const auto size = str.size();
    if (size < 2)
        throw std::invalid_argument("Not enough bytes provided: " + str);

    if (str.front() != '[' || str.back() != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    if (size == 2)
        return {};

    if (size < 4 || str[1] != '[' || str[size - 2] != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    const auto lines = splitWords(std::string_view(str.data() + 2, str.size() - 4), "],[");
    std::vector<std::vector<std::string> > stringMatrix(lines.size());

    std::ranges::transform(lines, stringMatrix.begin(), [](const auto &line) { return splitWords(line, ","); });
    return stringMatrix;
}

std::vector<std::vector<int> > Common::Util::String::parse2DVectorInt(const std::string &str) {
    const auto stringMatrix = parse2DVectorString(str);
    std::vector<std::vector<int> > intMatrix(stringMatrix.size());

    std::ranges::transform(stringMatrix, intMatrix.begin(), [](const auto &stringRow) {
        std::vector<int> intRow(stringRow.size());
        std::ranges::transform(stringRow, intRow.begin(), [](const auto &word) { return std::stoi(word); });
        return intRow;
    });

    return intMatrix;
}

std::vector<std::vector<char>> Common::Util::String::parse2DVectorChar(const std::string &str) {
    const auto stringMatrix = parse2DVectorString(str);
    std::vector<std::vector<char> > charMatrix(stringMatrix.size());

    std::ranges::transform(stringMatrix, charMatrix.begin(), [](const auto &stringRow) {
        std::vector<char> charRow(stringRow.size());
        std::ranges::transform(stringRow, charRow.begin(), [](const auto &word) { return word[0]; });
        return charRow;
    });

    return charMatrix;
}
