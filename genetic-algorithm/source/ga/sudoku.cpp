#include "ga/sudoku.hpp"

auto ga::sudoku::cell(const int x, const int y) -> detail::cell&
{
    return m_grid.at((y * detail::grid_w) + x);
}

auto ga::sudoku::cell(const int x, const int y) const -> const detail::cell&
{
    return m_grid.at((y * detail::grid_w) + x);
}

auto ga::sudoku::read(std::istream& stream) -> std::istream&
{
    auto c = char(0x0);
    auto i = int (0x0);

    m_grid = {};
    while ((i < m_grid.size()) && (stream >> c))
        if (c >= '0' && c <= '9') m_grid[i++] = detail::cell(c == '0', c);

    return stream;
}

auto ga::sudoku::write(std::ostream& stream) const -> std::ostream&
{
    static constexpr auto hline = "+-------+-------+-------+";
    static constexpr auto vline = '|';
    static constexpr auto space = ' ';
    static constexpr auto endl  = '\n';

    stream << hline << endl;
    for (auto y = 0; y < detail::grid_h; y++)
    {
        stream << vline;
        for (auto x = 0; x < detail::grid_w; x++)
        {
            const auto value = cell(x, y).value;
            stream << space << (value == '0' ? space : value);
            if ((x % detail::sub_grid_w) == 2)
                stream << space << vline;
        }

        stream << endl;
        if ((y % detail::sub_grid_h) == 2)
            stream << hline << endl;
    }

    return stream;
}
