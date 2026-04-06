#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "utils.hpp"
#include <algorithm>

void normalize(int &a, int &b);

template <typename Container> void fordJohnsonSort(Container &c) {
    if (c.size() <= 1)
        return ;
    
    else if (c.size() == 2) {
        normalize(c[0], c[1]);
        return ;
    }
    int straggler;
    bool hasStraggler;

    std::vector< std::pair<int,int> > pairs = createPairs(c, straggler, hasStraggler);

    std::vector<int> small, large;

    for (size_t i = 0; i < pairs.size(); i++) {
        small.push_back(pairs[i].first);
        large.push_back(pairs[i].second);
    }
    fordJohnsonSort(large);

    for (size_t i = 0; i < small.size(); i++) {
        typename Container::iterator it = std::lower_bound(large.begin(), large.end(), small[i]);
        large.insert(it, small[i]);
    }

    if (hasStraggler) {
        typename Container::iterator it = std::lower_bound(large.begin(), large.end(), straggler);
        large.insert(it, straggler);
    }

    c.clear();
    for (size_t i = 0; i < large.size(); i++)
        c.push_back(large[i]);
}

#endif