#include <library/codefores/CF1552F_Telepanting.h>
#include <iostream>
#include <vector>
#include <library/util/Arithmetic.h>

int binarySearch(const std::vector<int> &vec, const int num, int l, int r) {
    if (vec[l] >= num)
        return -1;

    while (l < r) {
        if (const int m = (l + r + 1) / 2; vec[m] < num) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    return r;
}

int Library::Codeforces::CF1552F::telepanting(const std::vector<int> &src, const std::vector<int> &des,
                                               const std::vector<int> &state) {
    const auto modulo = Library::Util::Arithmetic::getModuloFunction(998244353);
    const size_t N = src.size();
    std::vector<long long> prefixSum(N + 1);
    prefixSum[0] = 0;
    for (int i = 0; i < N; ++i) {
        const int index = binarySearch(src, des[i], 0, i - 1) + 1;
        prefixSum[i + 1] = modulo(
            prefixSum[i] + static_cast<long long>(src[i]) - static_cast<long long>(des[i]) + prefixSum[i] - prefixSum[
                index]);
    }
    long long ans = modulo(src.back() + 1);
    for (int i = 0; i < N; ++i) {
        if (state[i]) {
            ans = modulo(ans + prefixSum[i + 1] - prefixSum[i]);
        }
    }
    return static_cast<int>(modulo(ans));
}
