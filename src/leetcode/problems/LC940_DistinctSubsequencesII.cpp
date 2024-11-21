#include <array>
#include <vector>
#include <leetcode/problems/LC940_DistinctSubsequencesII.h>

int LeetCode::Problems::LC940::distinctSubseqII(const std::string &s) {
    const auto mod = [](const long long x) { return (x % 1'000'000'007 + 1'000'000'007) % 1'000'000'007; };
    std::vector<long long> count1(s.size(), 0);
    std::vector<long long> count2(s.size(), 0);
    std::array<int, 26> lastIndex{};
    lastIndex.fill(-1);

    count1[0] = 1;
    count2[0] = 1;
    lastIndex[s[0] - 'a'] = 0;

    for (int i = 1; i < s.size(); ++i) {
        const int charIndex = s[i] - 'a';
        count1[i] = mod(count1[i - 1] + count2[i - 1]);
        count2[i] = mod(count1[i - 1] + count2[i - 1]);
        if (lastIndex[charIndex] != -1) {
            count2[i] = mod(count2[i] - count1[lastIndex[charIndex]]);
        }
        lastIndex[charIndex] = i;
    }
    return static_cast<int>(mod(count1.back() + count2.back() - 1));
}
