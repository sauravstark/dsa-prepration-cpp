#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC94_BinaryTreeInorderTraversal.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC94_BinaryTreeInorderTraversal) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC94_BinaryTreeInorderTraversal.txt", 2);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto root = Util::Parser::parse<Library::LeetCode::Datatype::TreeNode *>(words[0]);
            const auto expected = Util::Parser::parse<std::vector<int> >(words[1]);

            const auto result = Library::LeetCode::LC94::inorderTraversal(root);
            ASSERT_EQ(expected, result);

            Library::LeetCode::Datatype::TreeNode::deleteTree(root);
        }
    }
}
