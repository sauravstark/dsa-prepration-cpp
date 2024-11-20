#include <leetcode/problems/LC297_SerializeAndDeserializeBinaryTree.h>

LeetCode::DataTypes::TreeNode* deserializeRecursive(const std::string &data, int& i) {
    const char ch = data[i++];

    if (ch == ']')
        return nullptr;

    std::string val(1, ch);
    while(data[i] != '[')
        val.push_back(data[i++]);

    auto* root = new LeetCode::DataTypes::TreeNode(std::stoi(val));

    i++;
    root->left = deserializeRecursive(data, i);
    i++;
    root->right = deserializeRecursive(data, i);
    i++;
    return root;
}

std::string LeetCode::Problems::LC297::serialize(const LeetCode::DataTypes::TreeNode *root) {
    if (root == nullptr)
        return "[]";

    return "[" + std::to_string(root->val) + serialize(root->left) + serialize(root->right) + "]";
}

LeetCode::DataTypes::TreeNode * LeetCode::Problems::LC297::deserialize(const std::string& data) {
    int i = 1;
    return deserializeRecursive(data, i);
}
