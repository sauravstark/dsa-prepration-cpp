#pragma once
#include <vector>

namespace Library::LeetCode::Datatype {
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode();

        explicit ListNode(int x);

        explicit ListNode(int x, ListNode *next);

        static ListNode *buildListFromVector(const std::vector<int> &vec);

        static bool compareLists(const ListNode *lhs, const ListNode *rhs);

        static void deleteList(ListNode *head);
    };
}
