#include <common/util/File.h>
#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC297_SerializeAndDeserializeBinaryTree.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC297_SerializeAndDeserializeBinaryTree) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC297_SerializeAndDeserializeBinaryTree.txt", 1);

    while(testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto input = Common::Util::String::parseVectorString(words[0]);
        const auto inputTree = LeetCode::DataTypes::TreeNode::buildTreeFromVector(input);
        const auto serializedTree = LeetCode::Problems::LC297::serialize(inputTree);
        const auto deserializedTree  = LeetCode::Problems::LC297::deserialize(serializedTree);

        ASSERT_TRUE(LeetCode::DataTypes::TreeNode::compareTrees(inputTree, deserializedTree));

        LeetCode::DataTypes::TreeNode::deleteTree(inputTree);
        LeetCode::DataTypes::TreeNode::deleteTree(deserializedTree);
    }
}
