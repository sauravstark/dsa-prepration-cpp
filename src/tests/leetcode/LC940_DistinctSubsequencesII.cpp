#include <gtest/gtest.h>
#include <library/leetcode/LC940_DistinctSubsequencesII.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC940_DistinctSubsequencesII) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC940_DistinctSubsequencesII.txt", 2);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto &s = words[0];
            const auto expected = std::stoi(words[1]);
            const auto result = Library::LeetCode::LC940::distinctSubseqII(s);
            EXPECT_EQ(expected, result);
        }
    }
}
