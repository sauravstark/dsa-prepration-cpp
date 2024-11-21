#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC94_BinaryTreeInorderTraversal.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC94_BinaryTreeInorderTraversal) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC94_BinaryTreeInorderTraversal.txt", 2);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto input = Common::Util::String::parseVectorString(words[0]);
        const auto expected = Common::Util::String::parseVectorInt(words[1]);

        const auto root = LeetCode::DataTypes::TreeNode::buildTreeFromVector(input);
        const auto result = LeetCode::Problems::LC94::inorderTraversal(root);
        ASSERT_EQ(expected, result);

        LeetCode::DataTypes::TreeNode::deleteTree(root);
    }
}
