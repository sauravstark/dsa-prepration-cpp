#include <library/leetcode/LC297_SerializeAndDeserializeBinaryTree.h>

Library::LeetCode::Datatype::TreeNode *deserializeRecursive(const std::string &data, int &i) {
    const char ch = data[i++];

    if (ch == ']')
        return nullptr;

    std::string val(1, ch);
    while (data[i] != '[')
        val.push_back(data[i++]);

    auto *root = new Library::LeetCode::Datatype::TreeNode(std::stoi(val));

    i++;
    root->left = deserializeRecursive(data, i);
    i++;
    root->right = deserializeRecursive(data, i);
    i++;
    return root;
}

std::string Library::LeetCode::LC297::serialize(const Library::LeetCode::Datatype::TreeNode *root) {
    if (root == nullptr)
        return "[]";

    return "[" + std::to_string(root->val) + serialize(root->left) + serialize(root->right) + "]";
}

Library::LeetCode::Datatype::TreeNode *Library::LeetCode::LC297::deserialize(const std::string &data) {
    int i = 1;
    return deserializeRecursive(data, i);
}
