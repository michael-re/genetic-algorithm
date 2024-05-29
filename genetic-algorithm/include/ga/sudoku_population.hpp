#pragma once

#ifndef GA_SUDOKU_POPULATION_HPP
#define GA_SUDOKU_POPULATION_HPP

#include "ga/puzzle_population.hpp"

namespace ga
{
    class sudoku_population final
        : public puzzle_population
    {
    public:
        explicit sudoku_population(const class sudoku& source, const std::size_t size);

        virtual auto cull(const float percent) -> void override;
        virtual auto new_generation()          -> void override;

        [[nodiscard]] virtual auto best_fitness()    const -> int               override;
        [[nodiscard]] virtual auto best_individual() const -> const individual& override;

    private:
        std::size_t m_size;
        individuals m_individuals;
    };
} // namespace ga

#endif // GA_SUDOKU_POPULATION_HPP
