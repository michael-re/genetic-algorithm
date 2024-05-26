#include "ga/sudoku_fitness.hpp"

auto ga::sudoku_fitness::how_fit(const puzzle& puzzle) const -> int
{
    const auto pointer = dynamic_cast<const sudoku* const>(&puzzle);
    return (pointer != nullptr)
         ? how_fit(*pointer)
         : throw std::invalid_argument("can't calculate fitness of a non-sudoku puzzle");
}

auto ga::sudoku_fitness::how_fit(const sudoku& puzzle) -> int
{
    auto fitness = solution; // assume we start with solution
    for (auto i = 0, origin_x = 0, origin_y = 0; i < sudoku::detail::grid_height; i++)
    {
        fitness += row_fitness(puzzle, i);
        fitness += col_fitness(puzzle, i);
        fitness += sub_fitness(puzzle, origin_x, origin_y);

        origin_y += sudoku::detail::sub_grid_height;
        if (origin_y == sudoku::detail::grid_height)
        {
            origin_x += sudoku::detail::grid_width;
            origin_y  = 0;
        }
    }

    return fitness;
}

auto ga::sudoku_fitness::row_fitness(const sudoku& puzzle, const int x) -> int
{
    auto duplicates = std::array<int, 10>();
    for (auto y = 0; y < sudoku::detail::grid_height; y++)
        duplicates[static_cast<std::size_t>(puzzle.cell(x, y).value - '0')]++;

    return (duplicates[0] == 0)
         ? compute_fitness(duplicates)
         : throw std::runtime_error("can't compute fitness of sudoku puzzle with invalid row");
}

auto ga::sudoku_fitness::col_fitness(const sudoku& puzzle, const int y) -> int
{
    auto duplicates = std::array<int, 10>();
    for (auto x = 0; x < sudoku::detail::grid_width; x++)
        duplicates[static_cast<std::size_t>(puzzle.cell(x, y).value - '0')]++;

    return (duplicates[0] == 0)
         ? compute_fitness(duplicates)
         : throw std::runtime_error("can't compute fitness of sudoku puzzle with invalid column");
}

auto ga::sudoku_fitness::sub_fitness(const sudoku& puzzle, const int origin_x, const int origin_y) -> int
{
    auto duplicates = std::array<int, 10>();
    for (auto y = origin_y; y < (origin_y + sudoku::detail::sub_grid_height); y++)
        for (auto x = origin_x; x < (origin_x + sudoku::detail::sub_grid_width); x++)
            duplicates[static_cast<std::size_t>(puzzle.cell(x, y).value - '0')]++;

    return (duplicates[0] == 0)
         ? compute_fitness(duplicates)
         : throw std::runtime_error("can't compute fitness of sudoku puzzle with invalid sub-grid");
}

template<typename Container>
auto ga::sudoku_fitness::compute_fitness(const Container& duplicates) -> int
{
    auto fitness = solution;
    for (const auto& count : duplicates)
        if (count > 1) fitness += (count == 2) ? 2 : (count * 2);
    return fitness;
}
