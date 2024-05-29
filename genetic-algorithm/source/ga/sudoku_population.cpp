#include <algorithm>

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
    if (percent != 0.0f)
    {
        const auto pop_cull_rate = static_cast<std::size_t>(m_size * std::min(1.0f, std::abs(percent)));
        const auto pop_cull_size = static_cast<std::ptrdiff_t>((m_size - pop_cull_rate) + 1u);
        const auto least_fit_beg = m_individuals.begin() + pop_cull_size;
        const auto least_fit_end = m_individuals.end();
        m_individuals.erase(least_fit_beg, least_fit_end);

        // remove at least one puzzle during cull phase
        if ((m_individuals.size() - 1) == m_size)
            m_individuals.pop_back();
    }
}

auto ga::sudoku_population::new_generation() -> void
{
    if (m_individuals.size() == 1)
    {
        // create new generation from progenitor
        m_individuals.reserve(m_size + 1);
        while ((m_individuals.size() - 1) != m_size)
            m_individuals.push_back(m_individuals.front().offspring());
    }
    else
    {
        // create new generation from most fit puzzles in old generation
        std::swap(m_individuals.front(), m_individuals.back());
        auto progenitor = std::move(m_individuals.back());
        m_individuals.pop_back();

        const auto old_generation = std::move(m_individuals);
        m_individuals.clear();
        m_individuals.reserve(m_size + 1);
        m_individuals.push_back(std::move(progenitor));

        while ((m_individuals.size() - 1) != m_size)
        {
            for (const auto& individual : old_generation)
            {
                m_individuals.push_back(individual.offspring());
                if ((m_individuals.size() - 1) == m_size) break;
            }
        }
    }

    // sort puzzles from most fit to least fit
    std::sort(m_individuals.begin() + 1, m_individuals.end());
}

auto ga::sudoku_population::best_fitness() const -> int
{
    return best_individual().fitness();
}

auto ga::sudoku_population::best_individual() const -> const individual&
{
    return m_individuals[1];
}
