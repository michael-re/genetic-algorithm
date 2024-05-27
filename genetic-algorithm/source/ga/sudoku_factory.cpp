#include "ga/sudoku_factory.hpp"
#include "ga/sudoku_offspring.hpp"

auto ga::sudoku_factory::reproduction() const -> const sudoku_offspring&
{
    static const auto reproduction = sudoku_offspring();
    return reproduction;
}

auto ga::sudoku_factory::create_puzzle(const puzzle& puzzle) const -> sudoku*
{
    return reproduction().make_offspring(puzzle);
}

auto ga::sudoku_factory::clone_puzzle(const puzzle& puzzle) const -> sudoku*
{
    return reproduction().clone_puzzle(puzzle);
}

auto ga::sudoku_factory::create_puzzle(const sudoku& puzzle) -> sudoku*
{
    return sudoku_offspring::make_offspring(puzzle);
}

auto ga::sudoku_factory::clone_puzzle(const sudoku& puzzle) -> sudoku*
{
    return sudoku_offspring::clone_puzzle(puzzle);
}
