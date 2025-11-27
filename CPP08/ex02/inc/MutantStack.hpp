#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <list>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

template <typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack& other) : std::stack<T>(other) {};
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        };

        typedef typename std::stack<T>::container_type::iterator iterator; // in order to bring back protected container from std::stack

        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
};