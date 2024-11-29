#pragma once
#include <string>
#include <vector>

namespace Tests::LeetCode::Util {
    class TestcaseReader {
    public:
        TestcaseReader(const std::string &fileName, int expectedWordCount);

        bool hasNext();

        std::vector<std::string> next();

    private:
        std::vector<std::string> fileLines;
        int fileLinesWordCount;
        std::vector<std::string>::iterator fileLinesIterator;
    };
}
