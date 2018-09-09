#include <type_traits>

namespace detail {
    template<bool a> std::enable_if_t<a, bool> id() {
        return true;
    }
    template<bool a> std::enable_if_t<!a, bool> id() {
        return false;
    }
}

template<class T> T foo(T, T = detail::id<sizeof(T) == 1>()) {
    return {};
}

int main() {
    foo(1);
}
