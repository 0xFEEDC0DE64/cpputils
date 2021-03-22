#pragma once

// system includes
#include <cstdint>
#include <stdexcept>

namespace cpputils {
template<typename T>
class basic_bit_pattern
{
    T expected{};
    T mask{};

public:
    template<std::size_t Size>
    explicit constexpr basic_bit_pattern(const char (&input)[Size])
    {
        T cur_bit = (1 << (Size - 2));
        for (const char val : input)
        {
            switch (val)
            {
            case 0:
                return;
            case '1':
                expected |= cur_bit;
            [[fallthrough]];
            case '0':
                mask |= cur_bit;
                break;
            case 'x':
            case 'X':
                break;
            default:
                throw std::logic_error{"Unknown characters in bit pattern input"};
            }

            cur_bit >>= 1;
        }
    }

    constexpr friend bool operator==(const T value, const basic_bit_pattern &pattern)
    {
        return (value & pattern.mask) == pattern.expected;
    }
};

using bit_pattern = basic_bit_pattern<std::uint32_t>;
} // namespace cpputils