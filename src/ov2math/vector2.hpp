#include <memory>
#include <concepts>
#include <ov2concepts.h>

namespace ov2::math
{
    template <number T>
    class vector2 final
    {
    public:
        T x, y;

    public:
        using element_type = T;
        using value_type = vector2<element_type>;
    
    public:
        constexpr vector2(const element_type x, const element_type y) noexcept : x{ x }, y{ y } {}

        constexpr value_type& operator= (const value_type& other) noexcept = default;
        
        constexpr value_type operator+=(const value_type& other) noexcept;
        constexpr value_type operator-=(const value_type& other) noexcept;

        constexpr bool operator==(const value_type& other) const noexcept;
        constexpr bool operator!=(const value_type& other) const noexcept;

        constexpr value_type operator+(const value_type& other) const noexcept;
        constexpr value_type operator-(const value_type& other) const noexcept;

        template<number U>
        friend constexpr value_type operator*(const value_type& v, const U scalar) noexcept
        {
            return { v.x * scalar, v.y * scalar };
        }
        template<number U>
        friend constexpr value_type operator*(const U scalar, const value_type& v) noexcept
        {
            return { v.x * scalar, v.y * scalar };
        }

        template<number U>
        friend constexpr value_type operator/(const value_type& v, const U scalar) noexcept
        {
            return { v.x / scalar, v.y / scalar };
        }


        constexpr [[nodiscard]] T* as_array();
    };

    template <number T>
    constexpr [[nodiscard]] T* vector2<T>::as_array()
    {
        return &x;
    }

    template <number T>
    constexpr bool vector2<T>::operator==(const value_type& other) const noexcept
    {
        return x == other.x && y == other.y;
    }

    template <number T>
    constexpr bool vector2<T>::operator!=(const value_type& other) const noexcept
    {
        return !(*this == other);
    }

    template <number T>
    constexpr vector2<T> vector2<T>::operator+(const value_type& other) const noexcept
    {
        return {x + other.x, y + other.y};
    }

    template <number T>
    constexpr vector2<T> vector2<T>::operator-(const value_type& other) const noexcept
    {
        return { x - other.x, y - other.y };
    }

}