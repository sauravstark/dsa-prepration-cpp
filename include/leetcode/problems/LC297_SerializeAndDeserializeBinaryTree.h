#pragma once
#include <string>
#include <leetcode/datatype/TreeNode.h>

namespace LeetCode::Problems::LC297 {
    std::string serialize(const DataTypes::TreeNode *root);
    DataTypes::TreeNode *deserialize(const std::string& data);
}
