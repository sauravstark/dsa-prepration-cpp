#include <library/leetcode/datatype/ListNode.h>

Library::LeetCode::Datatype::ListNode::ListNode(): val(0), next(nullptr) {
}

Library::LeetCode::Datatype::ListNode::ListNode(const int x): val(x), next(nullptr) {
}

Library::LeetCode::Datatype::ListNode::ListNode(const int x, ListNode *next): val(x), next(next) {
}

Library::LeetCode::Datatype::ListNode *Library::LeetCode::Datatype::ListNode::buildListFromVector(
    const std::vector<int> &vec) {
    ListNode dummy;
    ListNode *tail = &dummy;
    for (const auto val: vec) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

bool Library::LeetCode::Datatype::ListNode::compareLists(const ListNode *lhs, const ListNode *rhs) {
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs == rhs)
            return true;
        if (lhs->val != rhs->val)
            return false;
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return lhs == rhs;
}

void Library::LeetCode::Datatype::ListNode::deleteList(ListNode *head) {
    while (head != nullptr) {
        const auto temp = head->next;
        delete head;
        head = temp;
    }
}
