template<class T> T someFuncThatReturnsOne();

template<> float someFuncThatReturnsOne<float>() { return 1.0f; }

template<class T> struct Vec3 {
    constexpr Vec3(T r, T g, T b) noexcept: d{r, g, b} {}
    T d[3];
};

template<class T> struct Color3: Vec3<T> {
    constexpr Color3(T r, T g, T b) noexcept: Vec3<T>{r, g, b} {}
};

template<class T> struct Color4 {
    constexpr Color4(const Vec3<T>& rgb, T a = someFuncThatReturnsOne<T>()) noexcept: d{rgb.d[0], rgb.d[1], rgb.d[2], a} {}
    T d[4];
};

float foo(const Color4<float>& c) { return c.d[0]; }

int main() {
    return foo(Color3<float>(0, 0, 0));
}
