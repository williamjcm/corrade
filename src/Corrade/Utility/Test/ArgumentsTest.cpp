#include <type_traits>

namespace Implementation {

template<class T> constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type someFuncThatReturnsOne() {
    return T(1);
}
template<class T> constexpr typename std::enable_if<std::is_integral<T>::value, T>::type someFuncThatReturnsOne() {
    return {};
}

}

template<class T> constexpr T foo(T, T = Implementation::someFuncThatReturnsOne<T>()) { return T{}; }

int main() {
    foo(1.0f);
}
