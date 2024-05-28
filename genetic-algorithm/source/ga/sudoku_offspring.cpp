#include <chrono>
#include <random>

#include "ga/sudoku_offspring.hpp"

auto ga::sudoku_offspring::clone_puzzle(const puzzle& puzzle) const -> sudoku*
{
    const auto pointer = dynamic_cast<const sudoku* const>(&puzzle);
    return (pointer != nullptr)
         ? new sudoku(*pointer)
         : throw std::invalid_argument("can't clone non-sudoku puzzle");
}

auto ga::sudoku_offspring::make_offspring(const puzzle& puzzle) const -> sudoku*
{
    static auto time        = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    static auto seed        = std::random_device();
    static auto engine      = std::mt19937_64(seed() ^ static_cast<std::mt19937_64::result_type>(time));
    static auto mutation    = std::uniform_int_distribution<int>(0x1, 0x09);
    static auto probability = std::uniform_int_distribution<int>(0x0, 0x63);

    auto offspring = clone_puzzle(puzzle);
    for (auto i = 0; i < sudoku::detail::grid_size; i++)
    {
        const auto& [stochastic, value] = (*offspring)[i];
        if ((value == '0') || (stochastic && (5 >= probability(engine))))
            (*offspring)[i].value = static_cast<char>(mutation(engine) + '0');
    }

    return offspring;
}
