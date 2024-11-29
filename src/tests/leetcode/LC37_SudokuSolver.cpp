#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC37_SudokuSolver.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC37_SudokuSolver) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC37_SudokuSolver.txt", 2);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            auto board = Util::Parser::parse<std::vector<std::vector<char> > >(words[0]);
            const auto expected = Util::Parser::parse<std::vector<std::vector<char> > >(words[1]);

            Library::LeetCode::LC37::solveSudoku(board);
            ASSERT_EQ(expected, board);
        }
    }
}
