#include <library/util/Arithmetic.h>
#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC3351_SumOfGoodSubsequences.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC3351_SumOfGoodSubsequences) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC3351_SumOfGoodSubsequences.txt", 2);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto input = Util::Parser::parse<std::vector<int> >(words[0]);
            const auto expected = std::stoi(words[1]);
            const auto result = Library::LeetCode::LC3351::sumOfGoodSubsequences(input);
            ASSERT_EQ(expected, result);
        }
    }
}
