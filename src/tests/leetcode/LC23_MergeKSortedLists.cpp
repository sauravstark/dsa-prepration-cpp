#include <gtest/gtest.h>
#include <library/leetcode/LC23_MergeKSortedLists.h>
#include <library/leetcode/datatype/ListNode.h>
#include <vector>
#include <tests/util/String.h>
#include <tests/leetcode/util/TestcaseReader.h>
#include <tests/leetcode/util/Parser.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC23_MergeKSortedLists) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC23_MergeKSortedLists.txt", 2);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            auto lists = Util::Parser::parse<std::vector<Library::LeetCode::Datatype::ListNode *> >(words[0]);
            const auto expected = Util::Parser::parse<Library::LeetCode::Datatype::ListNode *>(words[1]);
            const auto result = Library::LeetCode::LC23::mergeKLists(lists);
            ASSERT_TRUE(Library::LeetCode::Datatype::ListNode::compareLists(expected, result));
            Library::LeetCode::Datatype::ListNode::deleteList(expected);
        }
    }
}
