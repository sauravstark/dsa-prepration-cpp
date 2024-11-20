#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC37_SudokuSolver.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC37_SudokuSolver) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC37_SudokuSolver.txt", 2);

    while(testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        auto board = Common::Util::String::parse2DVectorChar(words[0]);
        const auto expected = Common::Util::String::parse2DVectorChar(words[1]);

        LeetCode::Problems::LC37::solveSudoku(board);
        ASSERT_EQ(expected, board);
    }
}
