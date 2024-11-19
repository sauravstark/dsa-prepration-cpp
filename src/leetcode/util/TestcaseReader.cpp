#include <iostream>
#include <stdexcept>
#include <leetcode/util/TastcaseReader.h>
#include <ostream>
#include <common/util/File.h>
#include <common/util/String.h>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    if (vec.empty())
        return os << "[]";
    os << "[" << vec[0];
    for (size_t i = 1; i < vec.size(); i++) {
        os << "," << vec[i];
    }
    os << "]";
    return os;
}

LeetCode::Util::TestcaseReader::TestcaseReader(const std::string &fileName, const int expectedWordCount) {
    this->words = Common::Util::File::readLinesFromFile(fileName);
    this->expectedWordCount = expectedWordCount;
    this->currentWordItr = words.begin();

    if (this->words.empty()) {
        throw std::runtime_error("No testcases found");
    }
}

bool LeetCode::Util::TestcaseReader::hasNext() {
    return currentWordItr != words.end();
}

std::vector<std::string> LeetCode::Util::TestcaseReader::next() {
    std::vector<std::string> result = Common::Util::String::splitWords(*currentWordItr, " ");
    if (result.size() != expectedWordCount) {
        std::cout << "Expected " << expectedWordCount << " but got " << result.size() << " words." << std::endl;
        std::cout << "Testcase: " << result << std::endl;
        throw std::invalid_argument("Wrong number of words");
    }
    currentWordItr = std::next(currentWordItr);
    return result;
}
