#include <type_traits>

namespace detail {

template<bool a> constexpr typename std::enable_if<a, bool>::type id() {
    return true;
}
template<bool a> constexpr typename std::enable_if<!a, bool>::type id() {
    return false;
}

}

template<class T> constexpr T foo(T, bool = detail::id<sizeof(T) == 1>()) {
    return {};
}

int main() {
    foo(1.0f);
}
