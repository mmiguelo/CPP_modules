#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << R << "Error.\n[Usage]: " << av[0] << " <input>" << RST << std::endl;
        return 1;
    }
    PmergeMe merge;
    merge.readInput(ac, av);
    return 0;
}