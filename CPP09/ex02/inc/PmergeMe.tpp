#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include <algorithm>
#include <vector>

template <typename Container>
bool isSorted(const Container& input) {
	for (size_t i = 1; i < input.size(); i++) {
		if (input[i - 1] > input[i]) {
			return false;
		}
	}
	return true;
}

// Generates the Jacobsthal-based insertion order for n small elements
inline std::vector<size_t> jacobsthalOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;

    // Build Jacobsthal sequence until it exceeds n
    std::vector<size_t> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

    // index 0 is always inserted first
    order.push_back(0);

    for (size_t k = 2; k < jac.size(); k++) {
        size_t hi = std::min(jac[k], n);   // inclusive upper bound (1-indexed)
        size_t lo = jac[k - 1] + 1;        // inclusive lower bound (1-indexed)
        // Insert this group in reverse (hi down to lo), converting to 0-indexed
        for (size_t idx = hi; idx >= lo; idx--) {
            if (idx - 1 < n)
                order.push_back(idx - 1);
        }
    }
    return order;
}

template <typename Container>
std::vector< std::pair<int, int> > createPairs(const Container& input, int& straggler, bool& hasStraggler)
{
    std::vector< std::pair<int, int> > pairs;
    hasStraggler = false;

    size_t i = 0;
    for (; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];

        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (i < input.size())
    {
        straggler = input[i];
        hasStraggler = true;
    }
    else
        hasStraggler = false;

    return pairs;
}

template <typename Container>
void fordJohnsonSort(Container &c) {
    if (c.size() <= 1)
        return ;
    
    else if (c.size() == 2) {
        if (c[0] > c[1])
            std::swap(c[0], c[1]);
        return ;
    }
    int straggler;
    bool hasStraggler;

    std::vector< std::pair<int,int> > pairs = createPairs(c, straggler, hasStraggler);

    Container small, large;

    for (size_t i = 0; i < pairs.size(); i++) {
        small.push_back(pairs[i].first);
        large.push_back(pairs[i].second);
    }

    fordJohnsonSort(large);

    typename Container::iterator pos =
        std::lower_bound(large.begin(), large.end(), small[0]);
    large.insert(pos, small[0]);

    std::vector<size_t> order = jacobsthalOrder(small.size());
    for (size_t k = 1; k < order.size(); k++) {
        size_t idx = order[k];
        typename Container::iterator it =
            std::lower_bound(large.begin(), large.end(), small[idx]);
        large.insert(it, small[idx]);
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