#pragma once

#ifndef GA_PUZZLE_FACTORY_HPP
#define GA_PUZZLE_FACTORY_HPP

namespace ga
{
    class puzzle_factory
    {
    public:
        constexpr explicit puzzle_factory() = default;
        constexpr virtual ~puzzle_factory() = default;

        [[nodiscard]] virtual auto reproduction() const -> const class puzzle_offspring&     = 0;
        [[nodiscard]] virtual auto create_puzzle(const class puzzle&) const -> class puzzle* = 0;
        [[nodiscard]] virtual auto clone_puzzle (const class puzzle&) const -> class puzzle* = 0;
    };
} // namespace ga

#endif // GA_PUZZLE_FACTORY_HPP
