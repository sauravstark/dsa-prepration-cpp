#include <common/util/Arithmetic.h>
#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC3351_SumOfGoodSubsequences.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC3351_SumOfGoodSubsequences) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC3351_SumOfGoodSubsequences.txt", 2);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto input = Common::Util::String::parseVectorInt(words[0]);
        const auto expected = std::stoi(words[1]);
        const auto output = LeetCode::Problems::LC3351::sumOfGoodSubsequences(input);
        ASSERT_EQ(expected, output);
    }
}
