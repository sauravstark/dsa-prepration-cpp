#include <library/leetcode/LC94_BinaryTreeInorderTraversal.h>

std::vector<int> Library::LeetCode::LC94::inorderTraversal(Library::LeetCode::Datatype::TreeNode *root) {
    std::vector<int> result;

    Library::LeetCode::Datatype::TreeNode *temp = root;
    while (temp != nullptr) {
        if (temp->left == nullptr) {
            result.push_back(temp->val);
            temp = temp->right;
        } else {
            Library::LeetCode::Datatype::TreeNode *left = temp->left;
            temp->left = nullptr;
            Library::LeetCode::Datatype::TreeNode *temp2 = temp;
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
