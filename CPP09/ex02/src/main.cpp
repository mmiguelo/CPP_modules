#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << R << "Error.\n[Usage]: " << av[0] << " <input>" << RST << std::endl;
        return 1;
    }
    PmergeMe merge;
    merge.insertAndValidate(ac, av);

    {
    std::cout << "Before for vector: " << std::endl;
    for (size_t i = 0; i < merge.getBefore().size(); i++)
        std::cout << merge.getBefore()[i] << " ";
    std::cout << std::endl;
    clock_t start = clock();
    merge.populateVector();
    fordJohnsonSort(merge.getVector());
    clock_t end = clock();
    double elapsed_ms = double(end - start) * 1000 / CLOCKS_PER_SEC;

    std::cout << "After for vector: " << std::endl;
    for (size_t i = 0; i < merge.getVector().size(); i++)
        std::cout << merge.getVector()[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to sort Vector container: " << elapsed_ms << " ms" << std::endl;
    }

    {
    std::cout << "Before for deque: " << std::endl;
    for (size_t i = 0; i < merge.getBefore().size(); i++)
        std::cout << merge.getBefore()[i] << " ";
    std::cout << std::endl;
    clock_t start = clock();
    merge.populateDeque();
    fordJohnsonSort(merge.getDeque());
    clock_t end = clock();
    double elapsed_ms = double(end - start) * 1000 / CLOCKS_PER_SEC;

    std::cout << "After for deque: " << std::endl;
    for (size_t i = 0; i < merge.getDeque().size(); i++)
        std::cout << merge.getDeque()[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to sort Deque container: " << elapsed_ms << " ms" << std::endl;
    return 0;
    }
}