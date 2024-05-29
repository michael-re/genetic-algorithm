#include "ga/sudoku_population.hpp"
#include "ga/sudoku.hpp"

ga::sudoku_population::sudoku_population(const class sudoku& source, const std::size_t size)
    : m_size       (std::max<std::size_t>(1u, size)),
      m_individuals({ individual(source) })
{
    new_generation();
}

auto ga::sudoku_population::cull(const float percent) -> void
{
    static_cast<void>(percent);
}

auto ga::sudoku_population::new_generation() -> void
{
    
}

auto ga::sudoku_population::best_fitness() const -> int
{
    return best_individual().fitness();
}

auto ga::sudoku_population::best_individual() const -> const individual&
{
    return m_individuals[1];
}
