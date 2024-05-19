#pragma once

#ifndef GA_SUDOKU_HPP
#define GA_SUDOKU_HPP

#include <array>
#include <utility>

#include "ga/puzzle.hpp"

namespace ga
{
    class sudoku final
        : public puzzle
    {
    public:
        struct detail
        {
            static constexpr auto grid_w     = 9;
            static constexpr auto grid_h     = 9;
            static constexpr auto sub_grid_w = 3;
            static constexpr auto sub_grid_h = 3;

            struct cell
            {
                bool stochastic = true;
                char value      = '0';
            };

            using grid = std::array<cell, grid_w * grid_h>;
        };

    public:
        [[nodiscard]] auto cell(const int x, const int y)       ->       detail::cell&;
        [[nodiscard]] auto cell(const int x, const int y) const -> const detail::cell&;

        [[nodiscard]] virtual auto read (std::istream& stream)       -> std::istream& override;
        [[nodiscard]] virtual auto write(std::ostream& stream) const -> std::ostream& override;

    private:
        detail::grid m_grid = { };
    };
} // namespace ga

#endif // GA_SUDOKU_HPP
