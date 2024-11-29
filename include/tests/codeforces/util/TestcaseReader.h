#pragma once
#include <string>
#include <vector>

namespace Tests::Codeforces::Util {
    class TestcaseReader {
    public:
        explicit TestcaseReader(const std::string &fileName);

        int readInt();

        std::vector<int> readIntVector(size_t count);

        std::vector<std::vector<int> > readIntVector2D(size_t rowCount, size_t colCount);

    private:
        std::vector<std::string> words;
        std::vector<std::string>::iterator wordsItr;
    };

    std::vector<std::vector<int> > transpose(const std::vector<std::vector<int> > &input);
}
