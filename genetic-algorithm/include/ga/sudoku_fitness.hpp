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
        constexpr explicit sudoku_fitness()          = default;
        constexpr virtual ~sudoku_fitness() override = default;

        [[nodiscard]] virtual auto how_fit(const puzzle&) const -> int override;

    private:
        [[nodiscard]] static auto row_fitness(const sudoku&, const int x) -> int;
        [[nodiscard]] static auto col_fitness(const sudoku&, const int y) -> int;
        [[nodiscard]] static auto sub_fitness(const sudoku&, const int origin_x,
                                                             const int origin_y) -> int;

        template<typename Container>
        [[nodiscard]] static auto compute_fitness(const Container&) -> int;
    };
} // namespace ga

#endif // GA_SUDOKU_FITNESS_HPP
