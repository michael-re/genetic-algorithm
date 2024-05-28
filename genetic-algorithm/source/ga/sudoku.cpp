#include "ga/sudoku_factory.hpp"
#include "ga/sudoku_fitness.hpp"
#include "ga/sudoku.hpp"

auto ga::sudoku::operator[](const int index) -> detail::cell&
{
    return m_grid.at(static_cast<std::size_t>(index));
}

auto ga::sudoku::operator[](const int index) const -> const detail::cell&
{
    return m_grid.at(static_cast<std::size_t>(index));
}

auto ga::sudoku::cell(const int x, const int y) -> detail::cell&
{
    return (*this)[(y * detail::grid_width) + x];
}

auto ga::sudoku::cell(const int x, const int y) const -> const detail::cell&
{
    return (*this)[(y * detail::grid_width) + x];
}

auto ga::sudoku::clone() const -> sudoku*
{
    static constexpr auto factory = sudoku_factory();
    return factory.clone_puzzle(*this);
}

auto ga::sudoku::fitness() const -> int
{
    static constexpr auto evaluator = sudoku_fitness();
    return evaluator.how_fit(*this);
}

auto ga::sudoku::offspring() const -> sudoku*
{
    static constexpr auto factory = sudoku_factory();
    return factory.create_puzzle(*this);
}

auto ga::sudoku::read(std::istream &stream) -> std::istream &
{
    auto c = char       (0x0);
    auto i = std::size_t(0x0);

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
    for (auto y = 0; y < detail::grid_height; y++)
    {
        stream << vline;
        for (auto x = 0; x < detail::grid_width; x++)
        {
            const auto value = cell(x, y).value;
            stream << space << (value == '0' ? space : value);
            if ((x % detail::sub_grid_width) == 2)
                stream << space << vline;
        }

        stream << endl;
        if ((y % detail::sub_grid_height) == 2)
            stream << hline << endl;
    }

    return stream;
}
