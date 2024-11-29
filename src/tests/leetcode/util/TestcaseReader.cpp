#include <iostream>
#include <stdexcept>
#include <tests/leetcode/util/TestcaseReader.h>
#include <ostream>
#include <tests/util/File.h>
#include <tests/util/String.h>

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    if (vec.empty())
        return os << "[]";
    os << "[" << vec[0];
    for (size_t i = 1; i < vec.size(); i++) {
        os << "," << vec[i];
    }
    os << "]";
    return os;
}

Tests::LeetCode::Util::TestcaseReader::TestcaseReader(const std::string &fileName, const int expectedWordCount) {
    this->fileLines = Tests::Util::File::readLinesFromFile(fileName);
    this->fileLinesWordCount = expectedWordCount;
    this->fileLinesIterator = fileLines.begin();

    if (this->fileLines.empty()) {
        throw std::runtime_error("No testcases found");
    }
}

bool Tests::LeetCode::Util::TestcaseReader::hasNext() {
    return fileLinesIterator != fileLines.end();
}

std::vector<std::string> Tests::LeetCode::Util::TestcaseReader::next() {
    std::vector<std::string> result = Tests::Util::String::splitWords(*fileLinesIterator, " ");
    if (result.size() != fileLinesWordCount) {
        std::cout << "Expected " << fileLinesWordCount << " but got " << result.size() << " words." << std::endl;
        std::cout << "Testcase: " << result << std::endl;
        throw std::invalid_argument("Wrong number of words");
    }
    fileLinesIterator = std::next(fileLinesIterator);
    return result;
}
