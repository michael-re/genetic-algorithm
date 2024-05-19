#include "ga/puzzle.hpp"

auto ga::operator>>(std::istream& stream, puzzle& puzzle) -> std::istream&
{
    return puzzle.read(stream);
}

auto ga::operator<<(std::ostream& stream, const puzzle& puzzle) -> std::ostream&
{
    return puzzle.write(stream);
}
