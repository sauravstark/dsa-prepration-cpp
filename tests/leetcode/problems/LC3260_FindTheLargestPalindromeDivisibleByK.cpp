#include <gtest/gtest.h>
#include <leetcode/problems/LC3260_FindTheLargestPalindromeDivisibleByK.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC3260_FindTheLargestPalindromeDivisibleByK) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC3260_FindTheLargestPalindromeDivisibleByK.txt", 3);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const int n = std::stoi(words[0]);
        const int k = std::stoi(words[1]);
        const std::string output = LeetCode::Problems::LC3260::largestPalindrome(n, k);
        ASSERT_EQ(output, words[2]);
    }
}
