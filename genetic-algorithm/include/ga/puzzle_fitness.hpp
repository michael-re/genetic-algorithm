#pragma once

#ifndef GA_PUZZLE_FITNESS_HPP
#define GA_PUZZLE_FITNESS_HPP

#include "ga/puzzle.hpp"

namespace ga
{
    class puzzle_fitness
    {
    public:
        static constexpr auto invalid  = -1;
        static constexpr auto solution = 0;

    public:
        constexpr explicit puzzle_fitness() = default;
        constexpr virtual ~puzzle_fitness() = default;

        [[nodiscard]] virtual auto how_fit(const puzzle& puzzle) const -> int = 0;
    };
} // namespace ga

#endif // GA_PUZZLE_FITNESS_HPP
