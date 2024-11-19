#include <codefores/problems/CF1552F_Telepanting.h>
#include <common/util/File.h>
#include <common/util/String.h>
#include <gtest/gtest.h>

TEST(Codeforces, CF1552F_Telepanting) {
    const std::vector<std::string> lines = Common::Util::File::readLinesFromFile("testcases/codeforces/CF1552F_Telepanting.txt");
    int lineIndex = 0;
    const int  testcaseCount = std::stoi(lines[lineIndex++]);
    for (int i = 0; i < testcaseCount; i++) {
        const int N = std::stoi(lines[lineIndex++]);
        std::vector<int> src(N), des(N), state(N);
        for (int j = 0; j < N; j++) {
            std::vector<std::string> words = Common::Util::String::splitWords(lines[lineIndex++], " ");
            src[j] = std::stoi(words[0]);
            des[j] = std::stoi(words[1]);
            state[j] = std::stoi( words[2]);
        }
        const int expected = std::stoi(lines[lineIndex++]);
        const int actual = Codeforces::Problems::CF1552F::telepanting(src, des, state);
        ASSERT_EQ(expected, actual);
    }
}
