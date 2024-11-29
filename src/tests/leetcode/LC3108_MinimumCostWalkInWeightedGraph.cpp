#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC3108_MinimumCostWalkInWeightedGraph.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC3108_MinimumCostWalkInWeightedGraph) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC3108_MinimumCostWalkInWeightedGraph.txt", 4);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const int n = std::stoi(words[0]);
            auto edges = Util::Parser::parse<std::vector<std::vector<int> > >(words[1]);
            auto queries = Util::Parser::parse<std::vector<std::vector<int> > >(words[2]);
            auto expected = Util::Parser::parse<std::vector<int> >(words[3]);
            const auto result = Library::LeetCode::LC3108::minimumCost(n, edges, queries);
            ASSERT_EQ(expected, result);
        }
    }
}
