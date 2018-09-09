#include <type_traits>

namespace Implementation {

template<class T> constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type someFuncThatReturnsOne() {
    return T(1);
}
template<class T> constexpr typename std::enable_if<std::is_integral<T>::value, T>::type someFuncThatReturnsOne() {
    return {};
}

}

template<class T> struct Color4 {
    constexpr Color4(T a, T b = Implementation::someFuncThatReturnsOne<T>()) noexcept: d{a, b} {}
    T d[2];
};

constexpr float foo(const Color4<float>& c) { return c.d[1]; }

int main() {
    constexpr float a = Implementation::someFuncThatReturnsOne<float>();
    return a;
}
