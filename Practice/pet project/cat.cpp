#include"Cat.h"

Cat::Cat(std::string catName)://建構子
    Pet(catName)
{

}

void Cat::eat()
{
    decreaseHungry(20);
}

std::string Cat::getPetType() const 
{
    return "Cat";
}
