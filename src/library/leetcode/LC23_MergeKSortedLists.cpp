#include <queue>
#include <library/leetcode/LC23_MergeKSortedLists.h>

Library::LeetCode::Datatype::ListNode *Library::LeetCode::LC23::mergeKLists(std::vector<Datatype::ListNode *> &lists) {
    auto minHeapComparator = [](const Datatype::ListNode *lhs, const Datatype::ListNode *rhs) {
        return lhs->val > rhs->val;
    };

    std::priority_queue<Datatype::ListNode *, std::vector<Datatype::ListNode *>, decltype(minHeapComparator)> heap(
        minHeapComparator);
    for (auto node: lists)
        if (node != nullptr)
            heap.push(node);

    Datatype::ListNode dummy;
    Datatype::ListNode *tail = &dummy;

    while (!heap.empty()) {
        Datatype::ListNode *node = heap.top();
        heap.pop();
        if (node->next != nullptr)
            heap.push(node->next);

        tail->next = node;
        tail = node;
    }

    return dummy.next;
}
