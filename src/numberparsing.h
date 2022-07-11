#pragma once

// system includes
#include <cstdint>
#include <cstdio>
#include <inttypes.h>
#include <string>

// 3rdparty lib includes
#include <tl/expected.hpp>
#include <fmt/format.h>

namespace cpputils {
template<typename T> tl::expected<T, std::string> fromString(std::string_view str) = delete;

template<> inline tl::expected<int8_t, std::string> fromString<int8_t>(std::string_view str)
{
    int8_t val;
    if (std::sscanf(str.data(), "%" SCNi8, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid int8_t {}", str));
    return val;
}

template<> inline tl::expected<uint8_t, std::string> fromString<uint8_t>(std::string_view str)
{
    uint8_t val;
    if (std::sscanf(str.data(), "%" SCNu8, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid uint8_t {}", str));
    return val;
}

template<> inline tl::expected<int16_t, std::string> fromString<int16_t>(std::string_view str)
{
    int16_t val;
    if (std::sscanf(str.data(), "%" SCNi16, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid int16_t {}", str));
    return val;
}

template<> inline tl::expected<uint16_t, std::string> fromString<uint16_t>(std::string_view str)
{
    uint16_t val;
    if (std::sscanf(str.data(), "%" SCNu16, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid uint16_t {}", str));
    return val;
}

template<> inline tl::expected<int32_t, std::string> fromString<int32_t>(std::string_view str)
{
    int32_t val;
    if (std::sscanf(str.data(), "%" SCNi32, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid int32_t {}", str));
    return val;
}

template<> inline tl::expected<uint32_t, std::string> fromString<uint32_t>(std::string_view str)
{
    uint32_t val;
    if (std::sscanf(str.data(), "%" SCNu32, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid uint32_t {}", str));
    return val;
}

#ifdef ESP_PLATFORM
template<> inline tl::expected<long, std::string> fromString<long>(std::string_view str)
{
    long val;
    if (std::sscanf(str.data(), "%li", &val) != 1)
        return tl::make_unexpected(fmt::format("invalid long {}", str));
    return val;
}

template<> inline tl::expected<unsigned long, std::string> fromString<unsigned long>(std::string_view str)
{
    unsigned long val;
    if (std::sscanf(str.data(), "%lu", &val) != 1)
        return tl::make_unexpected(fmt::format("invalid unsigned long {}", str));
    return val;
}
#endif

template<> inline tl::expected<int64_t, std::string> fromString<int64_t>(std::string_view str)
{
    int64_t val;
    if (std::sscanf(str.data(), "%" SCNi64, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid int64_t {}", str));
    return val;
}

template<> inline tl::expected<uint64_t, std::string> fromString<uint64_t>(std::string_view str)
{
    uint64_t val;
    if (std::sscanf(str.data(), "%" SCNu64, &val) != 1)
        return tl::make_unexpected(fmt::format("invalid uint64_t {}", str));
    return val;
}
} // namespace cpputils
