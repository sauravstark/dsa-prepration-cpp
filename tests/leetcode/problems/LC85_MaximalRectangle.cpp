#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC85_MaximalRectangle.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC85_MaximalRectangle) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC85_MaximalRectangle.txt", 2);

    while(testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto matrix = Common::Util::String::parse2DVectorChar(words[0]);
        const auto expected = std::stoi(words[1]);

        const auto result = LeetCode::Problems::LC85::maximalRectangle(matrix);
        ASSERT_EQ(expected, result);
    }
}
