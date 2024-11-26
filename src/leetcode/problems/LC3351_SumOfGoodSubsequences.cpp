#include <unordered_map>
#include <ranges>
#include <common/util/Arithmetic.h>
#include <leetcode/problems/LC3351_SumOfGoodSubsequences.h>

int LeetCode::Problems::LC3351::sumOfGoodSubsequences(const std::vector<int> &nums) {
    std::unordered_map<int, std::pair<long long, long long>> lookupMap;

    const auto modulo = Common::Util::Arithmetic::getModuloFunction(1'000'000'007);

    for (int num : nums) {
        const auto [countN, sumN] = lookupMap[num];
        const auto [countNMinusOne, sumNMinusOne] = lookupMap[num - 1];
        const auto [countNPlusOne, sumNPlusOne] = lookupMap[num + 1];

        long long newCount = modulo(countN + countNMinusOne + countNPlusOne + 1);
        long long newSum = modulo(sumN + sumNMinusOne + sumNPlusOne + num + (countNMinusOne + countNPlusOne) * num);

        lookupMap[num] = {newCount, newSum};
    }

    long long ans = 0;
    for (auto const& countSumPair : std::views::values(lookupMap)) {
        auto [count, sum] = countSumPair;
        ans = modulo(ans + sum);
    }

    return static_cast<int>(ans);
}
