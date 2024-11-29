#include <tests/codeforces/util/TestcaseReader.h>
#include <tests/util/File.h>
#include <tests/util/String.h>

Tests::Codeforces::Util::TestcaseReader::TestcaseReader(const std::string &fileName) {
    for (auto fileLines = Tests::Util::File::readLinesFromFile(fileName); const auto &line: fileLines) {
        auto wordsInLine = Tests::Util::String::splitWords(line, " ");
        words.insert(words.end(), wordsInLine.begin(), wordsInLine.end());
    }
    wordsItr = words.begin();
}

int Tests::Codeforces::Util::TestcaseReader::readInt() {
    const auto ret = std::stoi(*wordsItr);
    wordsItr = std::next(wordsItr);
    return ret;
}

std::vector<int> Tests::Codeforces::Util::TestcaseReader::readIntVector(size_t count) {
    if (count == 0)
        count = readInt();

    std::vector<int> ret(count);
    for (size_t i = 0; i < count; i++)
        ret[i] = readInt();
    return ret;
}

std::vector<std::vector<int> > Tests::Codeforces::Util::TestcaseReader::readIntVector2D(
    size_t rowCount, size_t colCount) {
    if (rowCount == 0)
        rowCount = readInt();
    if (colCount == 0)
        colCount = readInt();
    std::vector ret(rowCount, std::vector<int>(colCount));
    for (size_t i = 0; i < rowCount; i++)
        for (size_t j = 0; j < colCount; j++)
            ret[i][j] = readInt();
    return ret;
}

std::vector<std::vector<int> > Tests::Codeforces::Util::transpose(const std::vector<std::vector<int> > &input) {
    std::vector ret(input[0].size(), std::vector<int>(input.size()));
    for (size_t i = 0; i < input.size(); i++)
        for (size_t j = 0; j < input[0].size(); j++)
            ret[j][i] = input[i][j];
    return ret;
}
