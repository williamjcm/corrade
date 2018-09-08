template<class T> T someFuncThatReturnsOne();

template<> constexpr unsigned char someFuncThatReturnsOne<unsigned char>() { return 255; }
template<> constexpr float someFuncThatReturnsOne<float>() { return 1.0f; }

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
    constexpr Color4(const Vec<3, T>& rgb, T a = someFuncThatReturnsOne<T>()) noexcept: Vec4<T>(rgb[0], rgb[1], rgb[2], a) {}
};

constexpr float foo(const Color4<float>& c) { return c.d[3]; }

int main() {
    constexpr float a = foo(Color3<float>(2.0f, 1.0f, 0.3f));
    return a;
}
