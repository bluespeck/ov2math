#pragma once

namespace ov2
{
    template <typename T>
    concept number = std::integral<T> || std::floating_point<T>;

}