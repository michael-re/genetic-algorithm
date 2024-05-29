#ifndef GA_GENETIC_ALGORITHM_HPP
#define GA_GENETIC_ALGORITHM_HPP

#include "ga/puzzle_population.hpp"
#include "ga/puzzle.hpp"

namespace ga::genetic_algorithm
{
    auto run(puzzle_population& population,
             const std::size_t  generations,
             const float        cull_rate) -> puzzle_population::individual;
} // namespace ga::genetic_algorithm

#endif // GA_GENETIC_ALGORITHM_HPP
