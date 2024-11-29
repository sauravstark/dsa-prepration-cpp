#pragma once

#include <functional>

namespace Library::Util::Arithmetic {
    std::function<long long (long long)> getModuloFunction(int mod);
}
