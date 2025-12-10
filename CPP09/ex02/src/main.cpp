#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << R << "Error.\n[Usage]: " << argv[0] << " <input>" << RST << std::endl;
        return 1;
    }
    
    return 0;
}