#pragma once

#ifndef GA_SUDOKU_OFFSPRING_HPP
#define GA_SUDOKU_OFFSPRING_HPP

#include "ga/puzzle_offspring.hpp"
#include "ga/sudoku.hpp"

namespace ga
{
    class sudoku_offspring final
        : public puzzle_offspring
    {
    public:
        constexpr explicit sudoku_offspring()          = default;
        constexpr virtual ~sudoku_offspring() override = default;

        [[nodiscard]] virtual auto clone_puzzle  (const puzzle& puzzle) const -> sudoku* override;
        [[nodiscard]] virtual auto make_offspring(const puzzle& puzzle) const -> sudoku* override;
    };
} // namespace ga

#endif // GA_SUDOKU_OFFSPRING_HPP
