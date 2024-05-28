#include <format>
#include <iostream>

#include "ga/puzzle_population.hpp"
#include "ga/sudoku.hpp"

auto main() -> int
{
    try
    {
        auto p = ga::sudoku();

        std::cout << "enter sudoku puzzle: ";
        std::cin  >> p;
        std::cout << std::endl << p << std::endl;

        return EXIT_SUCCESS;
    }
    catch(const std::exception& e)
    {
        static constexpr auto error = "\n==== exception ====\n";
        std::cerr << std::format("{}{}{}\n", error, e.what(), error);
        return EXIT_FAILURE;
    }
}
