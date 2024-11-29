#include <tests/util/File.h>
#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC297_SerializeAndDeserializeBinaryTree.h>
#include <tests/leetcode/util/TestcaseReader.h>
#include <tests/leetcode/util/Parser.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC297_SerializeAndDeserializeBinaryTree) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC297_SerializeAndDeserializeBinaryTree.txt", 1);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto inputTree = Tests::LeetCode::Util::Parser::parse<Library::LeetCode::Datatype::TreeNode
                *>(words[0]);
            const auto serialized = Library::LeetCode::LC297::serialize(inputTree);
            const auto outputTree = Library::LeetCode::LC297::deserialize(serialized);

            ASSERT_TRUE(Library::LeetCode::Datatype::TreeNode::compareTrees(inputTree, outputTree));

            Library::LeetCode::Datatype::TreeNode::deleteTree(inputTree);
            Library::LeetCode::Datatype::TreeNode::deleteTree(outputTree);
        }
    }
}
