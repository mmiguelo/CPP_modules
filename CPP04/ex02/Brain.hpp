#pragma once
#include <string>
#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &other);
        virtual ~Brain();
        Brain &operator=(const Brain &other);

        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;
        void printIdeas(int index) const;
};