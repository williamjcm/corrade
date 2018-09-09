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
template<class T> constexpr typename std::enable_if<std::is_integral<T>::value, T>::type someFuncThatReturnsOne() {
    return Implementation::bitMax<T>();
}

}


// template<> constexpr float someFuncThatReturnsOne<float>() { return 1.0f; }

template<int size, class T> struct Vec {
    template<class ...Args> constexpr Vec(Args... args) noexcept: d{args...} {}
    T d[size];

    T& operator[](int pos) { return d[pos]; }
    constexpr T operator[](int pos) const { return d[pos]; }
};

template<class T> struct Vec3: Vec<3, T> {
    constexpr Vec3(T r, T g, T b) noexcept: Vec<3, T>{r, g, b} {}
};

template<class T> struct Vec4: Vec<4, T> {
    constexpr Vec4(T r, T g, T b, T a) noexcept: Vec<4, T>{r, g, b, a} {}
};

template<class T> struct Color3: Vec3<T> {
    constexpr Color3(T r, T g, T b) noexcept: Vec3<T>{r, g, b} {}
};

template<class T> struct Color4: Vec4<T> {
    constexpr Color4(const Vec3<T>& rgb, T a = Implementation::someFuncThatReturnsOne<T>()) noexcept: Vec4<T>(rgb[0], rgb[1], rgb[2], a) {}
};

// constexpr Color3<float> bar(int a) { return {2.0f + a, 1.0f, 0.3f}; }

constexpr float foo(const Color4<float>& c) { return c.d[3]; }

int main() {
    float a = foo({{1.0f, 2.f, 3.0f}});
    return a;
}
