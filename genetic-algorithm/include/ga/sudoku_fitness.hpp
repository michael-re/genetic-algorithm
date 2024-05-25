#pragma once

#ifndef GA_SUDOKU_FITNESS_HPP
#define GA_SUDOKU_FITNESS_HPP

#include "ga/puzzle_fitness.hpp"
#include "ga/sudoku.hpp"

namespace ga
{
    class sudoku_fitness final
        : public puzzle_fitness
    {
    public:
        [[nodiscard]] virtual auto how_fit(const puzzle& puzzle) const -> int override;
    };
} // namespace ga

#endif // GA_SUDOKU_FITNESS_HPP
