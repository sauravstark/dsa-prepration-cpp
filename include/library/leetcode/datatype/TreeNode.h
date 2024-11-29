#pragma once
#include <vector>
#include <string>

namespace Library::LeetCode::Datatype {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode();

        explicit TreeNode(int x);

        explicit TreeNode(int x, TreeNode *left, TreeNode *right);

        static TreeNode *buildTreeFromVector(const std::vector<std::string> &vec);

        static bool compareTrees(const TreeNode *lhs, const TreeNode *rhs);

        static void deleteTree(const TreeNode *root);
    };
}
