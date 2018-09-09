#include <type_traits>

namespace detail {

template<int a> constexpr typename std::enable_if<a == 1, bool>::type byte() {
    return 1;
}
template<int a> constexpr typename std::enable_if<a != 1, bool>::type byte() {
    return 0;
}

}

template<class T> constexpr T foo(T, bool = detail::byte<sizeof(T)>()) { return {}; }

int main() {
    foo(1.0f);
}
