#include <queue>
#include <string>
#include <library/leetcode/datatype/TreeNode.h>

Library::LeetCode::Datatype::TreeNode::TreeNode(): val(0), left(nullptr), right(nullptr) {
}

Library::LeetCode::Datatype::TreeNode::TreeNode(const int x): val(x), left(nullptr), right(nullptr) {
}

Library::LeetCode::Datatype::TreeNode::TreeNode(const int x, TreeNode *left,
                                                TreeNode *right): val(x), left(left), right(right) {
}

Library::LeetCode::Datatype::TreeNode *Library::LeetCode::Datatype::TreeNode::buildTreeFromVector(
    const std::vector<std::string> &vec) {
    if (vec.empty())
        return nullptr;

    auto *root = new TreeNode(std::stoi(vec[0]));
    std::queue<TreeNode *> nodes;
    nodes.push(root);

    for (int i = 1; i < vec.size(); i += 2) {
        TreeNode *node = nodes.front();
        nodes.pop();

        if (vec[i] != "null") {
            node->left = new TreeNode(std::stoi(vec[i]));
            nodes.push(node->left);
        }
        if (i + 1 < vec.size() && vec[i + 1] != "null") {
            node->right = new TreeNode(std::stoi(vec[i + 1]));
            nodes.push(node->right);
        }
    }

    return root;
}

bool Library::LeetCode::Datatype::TreeNode::compareTrees(const TreeNode *lhs, const TreeNode *rhs) {
    if (lhs == rhs)
        return true;
    if (lhs == nullptr || rhs == nullptr)
        return false;
    if (lhs->val != rhs->val)
        return false;
    return compareTrees(lhs->left, rhs->left) && compareTrees(lhs->right, rhs->right);
}

void Library::LeetCode::Datatype::TreeNode::deleteTree(const TreeNode *root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
