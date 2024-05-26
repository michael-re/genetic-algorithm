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
        [[nodiscard]] static  auto how_fit(const sudoku& puzzle)       -> int;

    private:
        [[nodiscard]] static auto row_fitness(const sudoku& puzzle, const int x) -> int;
        [[nodiscard]] static auto col_fitness(const sudoku& puzzle, const int y) -> int;
        [[nodiscard]] static auto sub_fitness(const sudoku& puzzle, const int origin_x,
                                                                    const int origin_y) -> int;

        template<typename Container>
        [[nodiscard]] static auto compute_fitness(const Container& duplicates) -> int;
    };
} // namespace ga

#endif // GA_SUDOKU_FITNESS_HPP
