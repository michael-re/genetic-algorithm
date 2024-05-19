#include "ga/sudoku.hpp"

auto ga::sudoku::cell(const int x, const int y) -> detail::cell&
{
    return m_grid.at((y * detail::grid_w) + x);
}

auto ga::sudoku::cell(const int x, const int y) const -> const detail::cell&
{
    return m_grid.at((y * detail::grid_w) + x);
}

auto ga::sudoku::read(std::istream &stream) -> std::istream &
{
    throw std::runtime_error("unimplemented function - ga::sudoku::read");
}

auto ga::sudoku::write(std::ostream &stream) const -> std::ostream &
{
    throw std::runtime_error("unimplemented function - ga::sudoku::write");
}
