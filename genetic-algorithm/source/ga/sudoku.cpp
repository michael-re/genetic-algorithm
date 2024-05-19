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
    auto c = char(0x0);
    auto i = int (0x0);

    m_grid = {};
    while ((i < m_grid.size()) && (stream >> c))
        if (c >= '0' && c <= '9') m_grid[i++] = detail::cell(c == '0', c);

    return stream;
}

auto ga::sudoku::write(std::ostream &stream) const -> std::ostream &
{
    throw std::runtime_error("unimplemented function - ga::sudoku::write");
}
