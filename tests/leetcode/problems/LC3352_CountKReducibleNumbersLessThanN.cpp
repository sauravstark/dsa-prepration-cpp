#include <common/util/Arithmetic.h>
#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC3352_CountKReducibleNumbersLessThanN.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC3352_CountKReducibleNumbersLessThanN) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC3352_CountKReducibleNumbersLessThanN.txt", 3);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto& input1 = words[0];
        const auto input2 = std::stoi(words[1]);
        const auto expected = std::stoi(words[2]);
        const auto output = LeetCode::Problems::LC3352::countKReducibleNumbers(input1, input2);
        ASSERT_EQ(expected, output);
    }
}
