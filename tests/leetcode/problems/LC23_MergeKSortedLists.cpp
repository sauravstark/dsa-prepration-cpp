#include <gtest/gtest.h>
#include <leetcode/problems/LC23_MergeKSortedLists.h>
#include <leetcode/datatype/ListNode.h>
#include <vector>
#include <common/util/String.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC23_MergeKSortedLists) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC23_MergeKSortedLists.txt", 2);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto matrix = Common::Util::String::parse2DVectorInt(words[0]);
        const auto expected = Common::Util::String::parseVectorInt(words[1]);

        std::vector<LeetCode::Datatype::ListNode *> lists;
        for (const auto &vec: matrix)
            lists.push_back(LeetCode::Datatype::ListNode::buildListFromVector(vec));

        const auto expectedList = LeetCode::Datatype::ListNode::buildListFromVector(expected);
        const auto result = LeetCode::Problems::LC23::mergeKLists(lists);
        ASSERT_TRUE(LeetCode::Datatype::ListNode::compareLists(expectedList, result));
        LeetCode::Datatype::ListNode::deleteList(expectedList);
    }
}
