#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC3108_MinimumCostWalkInWeightedGraph.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC3108_MinimumCostWalkInWeightedGraph) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC3108_MinimumCostWalkInWeightedGraph.txt", 4);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const int n = std::stoi(words[0]);
        std::vector<std::vector<int> > edges = Common::Util::String::parse2DVectorInt(words[1]);
        std::vector<std::vector<int> > queries = Common::Util::String::parse2DVectorInt(words[2]);
        std::vector<int> expectedResult = Common::Util::String::parseVectorInt(words[3]);
        const auto result = LeetCode::Problems::LC3108::minimumCost(n, edges, queries);
        ASSERT_EQ(expectedResult, result);
    }
}
