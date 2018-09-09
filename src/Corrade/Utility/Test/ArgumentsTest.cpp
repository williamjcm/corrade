#include <type_traits>

namespace Implementation {

template<class T> constexpr typename std::enable_if<sizeof(T) == 1, int>::type someFuncThatReturnsOne() {
    return 1;
}
template<class T> constexpr typename std::enable_if<sizeof(T) != 1, int>::type someFuncThatReturnsOne() {
    return 0;
}

}

template<class T> constexpr T foo(T, T = Implementation::someFuncThatReturnsOne<T>()) { return {}; }

int main() {
    foo(1.0f);
}
