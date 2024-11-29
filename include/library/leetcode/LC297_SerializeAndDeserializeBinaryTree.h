#pragma once
#include <string>
#include <library/leetcode/datatype/TreeNode.h>

namespace Library::LeetCode::LC297 {
    std::string serialize(const Datatype::TreeNode *root);
    Library::LeetCode::Datatype::TreeNode *deserialize(const std::string& data);
}
