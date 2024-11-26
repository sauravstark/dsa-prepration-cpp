#pragma once

#include <functional>

namespace Common::Util::Arithmetic {
    std::function<long long (long long)> getModuloFunction(int mod);
}
