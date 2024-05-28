#pragma once

#ifndef GA_PUZZLE_HPP
#define GA_PUZZLE_HPP

#include <istream>
#include <ostream>

namespace ga
{
    class puzzle
    {
    public:
        constexpr explicit puzzle() = default;
        constexpr virtual ~puzzle() = default;

        [[nodiscard]] virtual auto clone()     const -> puzzle* = 0;
        [[nodiscard]] virtual auto fitness()   const -> int     = 0;
        [[nodiscard]] virtual auto offspring() const -> puzzle* = 0;

        [[nodiscard]] virtual auto read (std::istream& stream)       -> std::istream& = 0;
        [[nodiscard]] virtual auto write(std::ostream& stream) const -> std::ostream& = 0;
    };

    auto operator>>(std::istream& stream,       puzzle& puzzle) -> std::istream&;
    auto operator<<(std::ostream& stream, const puzzle& puzzle) -> std::ostream&;
} // namespace ga

#endif // GA_PUZZLE_HPP
