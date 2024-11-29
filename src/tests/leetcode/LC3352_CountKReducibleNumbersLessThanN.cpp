#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC3352_CountKReducibleNumbersLessThanN.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC3352_CountKReducibleNumbersLessThanN) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC3352_CountKReducibleNumbersLessThanN.txt", 3);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto &s = words[0];
            const auto k = std::stoi(words[1]);
            const auto expected = std::stoi(words[2]);
            const auto result = Library::LeetCode::LC3352::countKReducibleNumbers(s, k);
            ASSERT_EQ(expected, result);
        }
    }
}
