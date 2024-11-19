#include <codefores/problems/CF1552F_Telepanting.h>
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &vec, const int num, int l, int r) {
    if (vec[l] >= num)
        return -1;

    while(l < r) {
        if (const int m = (l + r + 1) / 2; vec[m] < num) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    return r;
}

int Codeforces::Problems::CF1552F::telepanting(const std::vector<int> &src, const std::vector<int> &des, const std::vector<int> &state) {
    const auto mod = [](const long long x) { return (x % 998244353 + 998244353) % 998244353; };
    const size_t N = src.size();
    std::vector<long long> prefixSum(N + 1);
    prefixSum[0] = 0;
    for (int i = 0; i < N; ++i) {
        const int index = binarySearch(src, des[i], 0, i - 1) + 1;
        prefixSum[i + 1] = mod(prefixSum[i] + static_cast<long long>(src[i]) - static_cast<long long>(des[i]) + prefixSum[i] - prefixSum[index]);
    }
    long long ans = mod(src.back() + 1);
    for (int i = 0; i < N; ++i) {
        if (state[i]) {
            ans = mod(ans + prefixSum[i + 1] - prefixSum[i]);
        }
    }
    return static_cast<int>(mod(ans));
}
