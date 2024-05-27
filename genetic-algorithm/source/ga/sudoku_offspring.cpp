#include <chrono>
#include <random>

#include "ga/sudoku_offspring.hpp"

auto ga::sudoku_offspring::clone_puzzle(const puzzle& puzzle) const -> sudoku*
{
    const auto pointer = dynamic_cast<const sudoku* const>(&puzzle);
    return (pointer != nullptr)
         ? clone_puzzle(*pointer)
         : throw std::invalid_argument("ca't clone non-sudoku puzzle");
}

auto ga::sudoku_offspring::make_offspring(const puzzle& puzzle) const -> sudoku*
{
    const auto pointer = dynamic_cast<const sudoku* const>(&puzzle);
    return (pointer != nullptr)
         ? make_offspring(*pointer)
         : throw std::invalid_argument("can't produce offspring of non-sudoku puzzle");
}

auto ga::sudoku_offspring::clone_puzzle(const sudoku& puzzle) -> sudoku*
{
    return new sudoku(puzzle);
}

auto ga::sudoku_offspring::make_offspring(const sudoku& puzzle) -> sudoku*
{
    static auto rde_s = std::random_device();
    static auto rng_1 = std::mt19937_64(rde_s());
    static auto rng_2 = std::mt19937_64(rde_s());
    static auto uid_1 = std::uniform_int_distribution<int>(0x1, 0x09); // cell mutation value
    static auto uid_2 = std::uniform_int_distribution<int>(0x0, 0x63); // cell mutation probability

    static const auto base        = 5;
    static const auto mutation    = []() { return uid_1(rng_1); };
    static const auto probability = []() { return uid_2(rng_2); };

    auto offspring = clone_puzzle(puzzle);
    for (auto i = 0; i < sudoku::detail::grid_size; i++)
    {
        const auto& [stochastic, value] = (*offspring)[i];
        if ((value == '0') || (stochastic && (base >= probability())))
            (*offspring)[i].value = static_cast<char>(mutation() + '0');
    }

    return offspring;
}
