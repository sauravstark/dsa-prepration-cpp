#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/datatype/TreeNode.h>
#include <library/leetcode/LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries) {
        Util::TestcaseReader testcaseReader(
            "testcases/leetcode/LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries.txt", 3);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto root = Tests::LeetCode::Util::Parser::parse<Library::LeetCode::Datatype::TreeNode *>(words[0]);
            const auto queries = Tests::LeetCode::Util::Parser::parse<std::vector<int> >(words[1]);
            const auto expected = Util::Parser::parse<std::vector<int> >(words[2]);

            if (queries.size() != expected.size()) {
                throw std::invalid_argument("Number of queries does not match number of results");
            }

            const auto result = Library::LeetCode::LC2458::treeQueries(root, queries);

            ASSERT_EQ(expected, result);

            Library::LeetCode::Datatype::TreeNode::deleteTree(root);
        }
    }
}
