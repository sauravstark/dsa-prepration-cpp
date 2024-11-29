#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC85_MaximalRectangle.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC85_MaximalRectangle) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC85_MaximalRectangle.txt", 2);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto matrix = Util::Parser::parse<std::vector<std::vector<char> > >(words[0]);
            const auto expected = std::stoi(words[1]);

            const auto result = Library::LeetCode::LC85::maximalRectangle(matrix);
            ASSERT_EQ(expected, result);
        }
    }
}
