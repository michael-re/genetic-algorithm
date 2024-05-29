#include <format>
#include <string>
#include <iostream>

#include "ga/genetic_algorithm.hpp"
#include "ga/sudoku_population.hpp"
#include "ga/sudoku_fitness.hpp"
#include "ga/sudoku.hpp"

auto main(const int argc, const char* argv[]) -> int
{
    if (argc != 3)
    {
        std::cerr << std::endl;
        std::cerr << std::format("usage: {} <population-size> <max-generation>", argv[0]);
        std::cerr << std::endl << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        auto source = ga::sudoku();
        std::cout << "enter sudoku puzzle: ";
        std::cin  >> source;

        std::cout << "\n\n===== source puzzle =====\n";
        std::cout << source << std::endl << std::endl;

        const auto cull_rate = 0.9f;
        const auto pop_size  = std::stoull(argv[1]);
        const auto max_gen   = std::stoull(argv[2]);

        auto population = ga::sudoku_population(source, pop_size);
        auto result     = ga::genetic_algorithm::run(population, max_gen, cull_rate);

        if (result.fitness() == ga::sudoku_fitness::solution)
            std::cout << "\n===== solution found =====\n";
        else
            std::cout << "\n===== solution NOT found =====\n";

        std::cout << "Fitness:    "  << result.fitness()    << "\n";
        std::cout << "Generation: "  << result.generation() << "\n";
        std::cout << result.puzzle() << "\n\n";

        return EXIT_SUCCESS;
    }
    catch(const std::exception& e)
    {
        static constexpr auto error = "\n==== exception ====\n";
        std::cerr << std::format("{}{}{}\n", error, e.what(), error);
        return EXIT_FAILURE;
    }
}
