#include <type_traits>

namespace detail {
    template<bool a> std::enable_if_t<a, bool> id() {
        return true;
    }
    template<bool a> std::enable_if_t<!a, bool> id() {
        return false;
    }
}

int foo(float, bool = detail::id<sizeof(float) == 1>()) {
    return {};
}

int main() {
    foo(1.0f);
}
