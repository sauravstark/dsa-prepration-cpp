#include <gtest/gtest.h>
#include <library/leetcode/LC3260_FindTheLargestPalindromeDivisibleByK.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC3260_FindTheLargestPalindromeDivisibleByK) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC3260_FindTheLargestPalindromeDivisibleByK.txt", 3);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const int n = std::stoi(words[0]);
            const int k = std::stoi(words[1]);
            const auto &expected = words[2];
            const std::string result = Library::LeetCode::LC3260::largestPalindrome(n, k);
            ASSERT_EQ(expected, result);
        }
    }
}
