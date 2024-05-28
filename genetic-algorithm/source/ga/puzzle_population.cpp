#include "ga/puzzle_population.hpp"
#include "ga/puzzle.hpp"

ga::puzzle_population::individual::individual(const ga::puzzle& source)
    : m_fitness   (source.fitness()),
      m_generation(0),
      m_puzzle    (source.clone())
{
}

ga::puzzle_population::individual::individual(ga::puzzle* puzzle)
    : m_fitness   (puzzle ? puzzle->fitness() : throw std::invalid_argument("can't compute fitness of null puzzle")),
      m_generation(0),
      m_puzzle    (puzzle ? puzzle : throw std::invalid_argument("can't take ownership of null puzzle"))
{
}

ga::puzzle_population::individual::~individual()
{
    delete m_puzzle;
    m_puzzle = nullptr;
}

ga::puzzle_population::individual::individual(individual&& other)
    : m_fitness   (std::exchange(other.m_fitness, -1)),
      m_generation(std::exchange(other.m_generation, 0)),
      m_puzzle    (std::exchange(other.m_puzzle, nullptr))
{
}

ga::puzzle_population::individual::individual(const individual& other)
    : m_fitness   (other.m_fitness),
      m_generation(other.m_generation),
      m_puzzle    (other.m_puzzle->clone())
{
}

auto ga::puzzle_population::individual::operator=(individual&& other) -> individual&
{
    std::swap(this->m_fitness,    other.m_fitness);
    std::swap(this->m_generation, other.m_generation);
    std::swap(this->m_puzzle,     other.m_puzzle);
    return *this;
}

auto ga::puzzle_population::individual::operator=(const individual& other) -> individual&
{
    if (this != &other)
    {
        delete m_puzzle;
        m_puzzle = nullptr;

        m_fitness    = other.m_fitness;
        m_generation = other.m_generation;
        m_puzzle     = other.m_puzzle->clone();
    }

    return *this;
}

auto ga::puzzle_population::individual::operator>(const individual& other) const -> bool
{
    return this->fitness() > other.fitness();
}

auto ga::puzzle_population::individual::operator<(const individual& other) const -> bool
{
    return this->fitness() < other.fitness();
}

auto ga::puzzle_population::individual::offspring() const -> individual
{
    auto offspring = individual(m_puzzle->offspring());
    offspring.m_generation = m_generation + 1;
    return offspring;
}

auto ga::puzzle_population::individual::fitness() const -> int
{
    return m_fitness;
}

auto ga::puzzle_population::individual::generation() const -> std::size_t
{
    return m_generation;
}

auto ga::puzzle_population::individual::puzzle() const -> const ga::puzzle&
{
    return *m_puzzle;
}
