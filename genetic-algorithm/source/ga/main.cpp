#include <format>
#include <iostream>

auto main() -> int
{
    try
    {
        std::cout << "hello world!\n";
        return EXIT_SUCCESS;
    }
    catch(const std::exception& e)
    {
        static constexpr auto error = "\n==== exception ====\n";
        std::cerr << std::format("{}{}{}\n", error, e.what(), error);
        return EXIT_FAILURE;
    }
}
