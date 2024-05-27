#pragma once

#ifndef GA_PUZZLE_OFFSPRING_HPP
#define GA_PUZZLE_OFFSPRING_HPP

#include "ga/puzzle.hpp"

namespace ga
{
    class puzzle_offspring
    {
    public:
        constexpr explicit puzzle_offspring() = default;
        constexpr virtual ~puzzle_offspring() = default;

        [[nodiscard]] virtual auto clone_puzzle  (const puzzle& puzzle) const -> ga::puzzle* = 0;
        [[nodiscard]] virtual auto make_offspring(const puzzle& puzzle) const -> ga::puzzle* = 0;
    };
} // namespace ga

#endif // GA_PUZZLE_OFFSPRING_HPP
