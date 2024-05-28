#pragma once

#ifndef GA_PUZZLE_POPULATION_HPP
#define GA_PUZZLE_POPULATION_HPP

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

namespace ga
{
    class puzzle_population
    {
    public:
        class individual;
        using individuals = std::vector<individual>;

    private:
        std::size_t m_size       = {};
        individuals m_population = {};
    };

    class puzzle_population::individual
    {
    public:
        explicit individual(const class puzzle&);
        explicit individual(class puzzle*);

        ~individual();

        individual(individual&&);
        individual(const individual&);

        [[nodiscard]] auto operator=(individual&&)      -> individual&;
        [[nodiscard]] auto operator=(const individual&) -> individual&;

        [[nodiscard]] auto operator>(const individual&) const -> bool;
        [[nodiscard]] auto operator<(const individual&) const -> bool;

        [[nodiscard]] auto offspring()  const -> individual;
        [[nodiscard]] auto fitness()    const -> int;
        [[nodiscard]] auto generation() const -> std::size_t;
        [[nodiscard]] auto puzzle()     const -> const ga::puzzle&;

    private:
        int           m_fitness;
        std::size_t   m_generation;
        class puzzle* m_puzzle;
    };
} // namespace ga

#endif // GA_PUZZLE_POPULATION_HPP
