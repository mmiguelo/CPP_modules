#include "../Animal.hpp"
#include "../Dog.hpp"
#include "../Cat.hpp"
#include "../WrongCat.hpp"
#include "../WrongAnimal.hpp"
#include "../Brain.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
	// Dog
    {
    std::cout << GREEN << "Creation of originalDog with default constructor" << RESET <<  std::endl;

    Dog originalDog;
    std::cout << originalDog.getType() << std::endl;
    std::string idea = "Boots, boots, boots, boots";
    originalDog.getBrain()->setIdea(0, idea);
    std::cout << RED;
    originalDog.getBrain()->printIdeas(0);
    std::cout << RESET << std::endl;
    

    std::cout<< GREEN  << "Creation of copiedDog with copy constructor" << RESET << std::endl;

    Dog copiedDog(originalDog);
    idea = "Movin' up an' down again";
    copiedDog.getBrain()->setIdea(1, idea);
	std::cout << RED;
    copiedDog.getBrain()->printIdeas(0);
    copiedDog.getBrain()->printIdeas(1);
    std::cout << RESET << std::endl;

    std::cout <<GREEN  << "Creation of assignedDog and (copy assignment of copiedDog)" << RESET << std::endl;
    Dog assignedDog;
    assignedDog = copiedDog;
    std::cout << RED;
    assignedDog.getBrain()->printIdeas(0);
    assignedDog.getBrain()->printIdeas(1);
    std::cout << RESET << std::endl;
    }

    // Cat
    {
    std::cout << GREEN << "\n\nCreation of originalCat with default constructor" << RESET <<  std::endl;

    Cat originalCat;
    std::cout << originalCat.getType() << std::endl;
    std::string idea = "Boots, boots, boots, boots, movin' up an' down again";
    originalCat.getBrain()->setIdea(0, idea);
    std::cout << RED;
    originalCat.getBrain()->printIdeas(0);
    std::cout << RESET << std::endl;
    

    std::cout<< GREEN  << "Creation of copiedCat with copy constructor" << RESET << std::endl;

    Cat copiedCat(originalCat);
    idea = "Men, men, men, men, men go mad with watchin' em,";
    copiedCat.getBrain()->setIdea(1, idea);
    std::cout << RED;
    copiedCat.getBrain()->printIdeas(0);
    copiedCat.getBrain()->printIdeas(1);
    std::cout << RESET << std::endl;

    std::cout <<GREEN  << "Creation of assignedCat and (copy assignment of copiedCat)" << RESET << std::endl;
    Cat assignedCat;
    assignedCat = copiedCat;
    std::cout << RED;
    assignedCat.getBrain()->printIdeas(0);
    assignedCat.getBrain()->printIdeas(1);
    std::cout << RESET << std::endl;
    }

    // Virtual destructors
    {
        std::cout << GREEN << "\n\nAnimal Arrays (5 Dogs + 5 Cats)" << RESET <<  std::endl;

        Animal *array[10];
        std::string dogIdea = "Oh, my, God, keep me from goin' lunatic!";
        std::string catIdea = "There's no discharge in the war!";
        
        for (int i = 0; i < 10; i++)
        {
            if (i < 5) // dogs
                array[i] = new Dog();   
            else // cats
                array[i] = new Cat();
        }

        std::cout << GREEN << "\n\nAnimals make sounds:" << RESET <<  std::endl;
        for (int i = 0; i < 10; i++)
            array[i]->makeSound();


        std::cout << GREEN << "\n\nFreeing memory" << RESET <<  std::endl;
        for (int i = 0; i < 10; i++)
            delete array[i];   
    }
    return 0;
}