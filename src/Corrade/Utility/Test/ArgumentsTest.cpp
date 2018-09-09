#include <type_traits>

namespace Implementation {

template<int a> constexpr typename std::enable_if<a == 1, int>::type yay() {
    return 1;
}
template<int a> constexpr typename std::enable_if<a != 1, int>::type yay() {
    return 0;
}

}

template<class T> constexpr T foo(T, T = Implementation::yay<sizeof(T)>()) { return {}; }

int main() {
    foo(1.0f);
}
