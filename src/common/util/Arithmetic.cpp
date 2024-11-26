#include <common/util/Arithmetic.h>

std::function<long long (long long)> Common::Util::Arithmetic::getModuloFunction(int mod) {
    return [mod](const long long x) {
        return (x % mod + mod) % mod;
    };
}
