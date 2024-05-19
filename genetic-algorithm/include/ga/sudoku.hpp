#pragma once

#ifndef GA_SUDOKU_HPP
#define GA_SUDOKU_HPP

#include "ga/puzzle.hpp"

namespace ga
{
    class sudoku final
        : public puzzle
    {
    public:
        [[nodiscard]] virtual auto read (std::istream& stream)       -> std::istream& override;
        [[nodiscard]] virtual auto write(std::ostream& stream) const -> std::ostream& override;
    };
} // namespace ga

#endif // GA_SUDOKU_HPP
