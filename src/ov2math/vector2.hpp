#include <memory>

namespace ov2::math
{
    template <typename T>
    class vector2 final
    {
    public:
        using element_type = T;
    public:
        element_type x, y;

    public:
        constexpr vector2(element_type x, element_type y) noexcept;

        constexpr vector2<element_type>& operator= (const vector2<element_type>& other) noexcept;

        constexpr bool operator==(const vector2<element_type>& other) const noexcept;
        constexpr bool operator!=(const vector2<element_type>& other) const noexcept;

        constexpr [[nodiscard]] T* as_array();
    };

    template <typename T>
    constexpr vector2<T>::vector2(T x, T y) noexcept
        : x{ x }, y{ y }
    {

    }

    template <typename T>
    constexpr [[nodiscard]] T* vector2<T>::as_array()
    {
        return &x;
    }

    template <typename T>
    constexpr vector2<T>& vector2<T>::operator= (const vector2<T>& other) noexcept
    {
        x = other.x;
        y = other.y;
        return *this;
    }
    template <typename T>
    constexpr bool vector2<T>::operator==(const vector2<T>& other) const noexcept
    {
        return x == other.x && y == other.y;
    }

    template <typename T>
    constexpr bool vector2<T>::operator!=(const vector2<T>& other) const noexcept
    {
        return !(*this == other);
    }

}