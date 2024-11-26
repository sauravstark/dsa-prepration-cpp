#include <vector>
#include <common/util/Arithmetic.h>
#include <leetcode/problems/LC3352_CountKReducibleNumbersLessThanN.h>

const auto modulo = Common::Util::Arithmetic::getModuloFunction(1'000'000'007);

long long combination(const size_t n, const size_t k) {
    if (n < k)
        return 0;

    static std::vector<std::vector<long long>> lookupTable = {{1}};

    for (auto i = lookupTable.size(); i <= n; ++i) {
        lookupTable.emplace_back(i + 1);
        lookupTable[i].front() = 1;
        lookupTable[i].back() = 1;
        for (auto j = 1; j < i; ++j) {
            lookupTable[i][j] = modulo(lookupTable[i - 1][j - 1] + lookupTable[i - 1][j]);
        }
    }
    return lookupTable[n][k];
}

long long countSmallerNumbers(const int n, const std::string& upperLimit) {
    long long count = 0;

    int bitCount = n;
    for (int i = 0; i < upperLimit.size(); ++i) {
        if (upperLimit[i] == '0')
            continue;
        count = modulo(count + combination(upperLimit.size() - i - 1, bitCount));
        bitCount--;
    }

    return count;
}

int countBits(const int num) {
    int count = 0;
    for (int x = num; x > 0; x /= 2)
        if ((x & 1) == 1)
            ++count;

    return count;
}

int LeetCode::Problems::LC3352::countKReducibleNumbers(const std::string &s, const int k) {
    std::vector<int> kLookupMap(s.size() + 1);
    kLookupMap[0] = -1;
    kLookupMap[1] = 0;
    for(int i = 2; i < kLookupMap.size(); ++i) {
        const int bitCount = countBits(i);
        kLookupMap[i] = kLookupMap[bitCount] + 1;
    }

    long long ans = 0;
    for (int i = 1; i < kLookupMap.size(); ++i) {
        if (kLookupMap[i] < k) {
            ans = modulo(ans + countSmallerNumbers(i, s));
        }
    }

    return static_cast<int>(ans);
}
