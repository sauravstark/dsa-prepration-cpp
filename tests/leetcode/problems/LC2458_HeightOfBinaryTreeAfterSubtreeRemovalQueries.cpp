#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/datatype/TreeNode.h>
#include <leetcode/problems/LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries) {
    LeetCode::Util::TestcaseReader testcaseReader(
        "testcases/leetcode/LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries.txt", 3);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto input = Common::Util::String::parseVectorString(words[0]);
        const auto queries = Common::Util::String::parseVectorInt(words[1]);
        const auto expectedResult = Common::Util::String::parseVectorInt(words[2]);
        const auto inputTree = LeetCode::DataTypes::TreeNode::buildTreeFromVector(input);

        if (queries.size() != expectedResult.size()) {
            throw std::invalid_argument("Number of queries does not match number of results");
        }

        const auto result = LeetCode::Problems::LC2458::treeQueries(inputTree, queries);

        ASSERT_EQ(expectedResult, result);

        LeetCode::DataTypes::TreeNode::deleteTree(inputTree);
    }
}
