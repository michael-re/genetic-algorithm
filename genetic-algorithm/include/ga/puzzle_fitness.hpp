#pragma once

#ifndef GA_PUZZLE_FITNESS_HPP
#define GA_PUZZLE_FITNESS_HPP

#include "ga/puzzle.hpp"

namespace ga
{
    class puzzle_fitness
    {
    public:
        static constexpr auto invalid  = int(-1);
        static constexpr auto solution = int(0);

    public:
        explicit puzzle_fitness() = default;
        virtual ~puzzle_fitness() = default;

        [[nodiscard]] virtual auto how_fit(const puzzle& puzzle) const -> int = 0;
    };
} // namespace ga

#endif // GA_PUZZLE_FITNESS_HPP
