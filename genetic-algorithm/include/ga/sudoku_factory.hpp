#pragma once

#ifndef GA_SUDOKU_FACTORY_HPP
#define GA_SUDOKU_FACTORY_HPP

#include "ga/sudoku_offspring.hpp"
#include "ga/puzzle_factory.hpp"

namespace ga
{
    class sudoku_factory final
        : public puzzle_factory
    {
    public:
        constexpr explicit sudoku_factory()          = default;
        constexpr virtual ~sudoku_factory() override = default;

        [[nodiscard]] virtual auto reproduction() const -> const sudoku_offspring& override;
        [[nodiscard]] virtual auto create_puzzle(const puzzle&) const -> sudoku* override;
        [[nodiscard]] virtual auto clone_puzzle (const puzzle&) const -> sudoku* override;
    };
} // namespace ga

#endif // GA_SUDOKU_FACTORY_HPP
