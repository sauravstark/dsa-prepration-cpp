#pragma once
#include <string>
#include <vector>

namespace LeetCode::Util {
    class TestcaseReader {
    public:
        TestcaseReader(const std::string& fileName, int expectedWordCount);
        bool hasNext();
        std::vector<std::string> next();
    private:
        std::vector<std::string> words;
        int expectedWordCount;
        std::vector<std::string>::iterator currentWordItr;
    };
}
