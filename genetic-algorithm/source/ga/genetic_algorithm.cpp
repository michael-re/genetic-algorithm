#include <iostream>

#include "ga/genetic_algorithm.hpp"
#include "ga/puzzle_fitness.hpp"

auto ga::genetic_algorithm::run(puzzle_population& population,
                                const std::size_t   generations,
                                const float         cull_rate) -> puzzle_population::individual
{
    auto best       = population.best_individual();
    auto generation = std::size_t(0);
    while ((generation < generations) && (best.fitness() != puzzle_fitness::solution))
    {
        std::cout << "\33[2K\r" << "best fitness: " << best.fitness()
                                << ", generation: " << generation << " of " << generations;
        std::cout.flush();

        population.cull(cull_rate);
        population.new_generation();
        generation++;

        if (population.best_fitness() < best.fitness())
            best = population.best_individual();
    }

    std::cout << "\33[2K\r";
    std::cout.flush();
    return best;
}
