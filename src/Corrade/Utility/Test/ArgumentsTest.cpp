#include <type_traits>

namespace detail {
    template<int a> std::enable_if_t<a, int> id() {
        return true;
    }
    template<int a> std::enable_if_t<!a, int> id() {
        return false;
    }
}

template<class T> T foo(T, int = detail::id<sizeof(T) == 1>()) {
    return {};
}

int main() {
    foo(1);
}
