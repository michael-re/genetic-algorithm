#pragma once

#ifndef GA_SUDOKU_FACTORY_HPP
#define GA_SUDOKU_FACTORY_HPP

#include "ga/puzzle_factory.hpp"
#include "ga/sudoku_offspring.hpp"
#include "ga/sudoku.hpp"

namespace ga
{
    class sudoku_factory final
        : public puzzle_factory
    {
    public:
        [[nodiscard]] virtual auto reproduction() const -> const sudoku_offspring& override;
        [[nodiscard]] virtual auto create_puzzle(const puzzle& puzzle) const -> sudoku* override;
        [[nodiscard]] virtual auto clone_puzzle (const puzzle& puzzle) const -> sudoku* override;

        [[nodiscard]] static auto create_puzzle(const sudoku& puzzle) -> sudoku*;
        [[nodiscard]] static auto clone_puzzle (const sudoku& puzzle) -> sudoku*;
    };
} // namespace ga

#endif // GA_SUDOKU_FACTORY_HPP
