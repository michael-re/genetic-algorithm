#pragma once

#ifndef GA_PUZZLE_FACTORY_HPP
#define GA_PUZZLE_FACTORY_HPP

#include "ga/puzzle_offspring.hpp"
#include "ga/puzzle.hpp"

namespace ga
{
    class puzzle_factory
    {
    public:
        explicit puzzle_factory() = default;
        virtual ~puzzle_factory() = default;

        [[nodiscard]] virtual auto reproduction() const -> const puzzle_offspring& = 0;

        [[nodiscard]] virtual auto create_puzzle(const puzzle& puzzle) const -> ga::puzzle* = 0;
        [[nodiscard]] virtual auto clone_puzzle (const puzzle& puzzle) const -> ga::puzzle* = 0;
    };
} // namespace ga

#endif // GA_PUZZLE_FACTORY_HPP
