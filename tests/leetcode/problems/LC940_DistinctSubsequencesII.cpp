#include <gtest/gtest.h>
#include <leetcode/problems/LC940_DistinctSubsequencesII.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC940_DistinctSubsequencesII) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC940_DistinctSubsequencesII.txt", 2);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto &input = words[0];
        const auto expected = std::stoi(words[1]);
        const auto result = LeetCode::Problems::LC940::distinctSubseqII(input);
        EXPECT_EQ(expected, result);
    }
}
