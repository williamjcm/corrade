#include <type_traits>

namespace Implementation {

template<class T, unsigned int bits = sizeof(T)*8> inline constexpr T bitMax() {
    return T(typename std::make_unsigned<T>::type(~T{}) >> (sizeof(T)*8 - (std::is_signed<T>::value ? bits - 1 : bits)));
}

// template<class T> T someFuncThatReturnsOne();
//
// template<> constexpr unsigned char someFuncThatReturnsOne<unsigned char>() { return 255; }
template<class T> constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type someFuncThatReturnsOne() {
    return T(1);
}
// template<class T> constexpr typename std::enable_if<std::is_integral<T>::value, T>::type someFuncThatReturnsOne() {
//     return Implementation::bitMax<T>();
// }

}

template<class T> struct Color4 {
    constexpr Color4(T a, T b = Implementation::someFuncThatReturnsOne<T>()) noexcept: d{a, b} {}
    T d[2];
};

// constexpr Color3<float> bar(int a) { return {2.0f + a, 1.0f, 0.3f}; }

constexpr float foo(const Color4<float>& c) { return c.d[1]; }

int main() {
    float a = foo({1.0f});
    return a;
}
