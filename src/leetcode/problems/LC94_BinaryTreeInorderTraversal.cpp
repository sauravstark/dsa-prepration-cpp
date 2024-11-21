#include <leetcode/problems/LC94_BinaryTreeInorderTraversal.h>

std::vector<int> LeetCode::Problems::LC94::inorderTraversal(DataTypes::TreeNode *root) {
    std::vector<int> result;

    DataTypes::TreeNode *temp = root;
    while (temp != nullptr) {
        if (temp->left == nullptr) {
            result.push_back(temp->val);
            temp = temp->right;
        } else {
            DataTypes::TreeNode *left = temp->left;
            temp->left = nullptr;
            DataTypes::TreeNode *temp2 = temp;
            temp = left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = temp2;
            temp = left;
        }
    }

    return result;
}
