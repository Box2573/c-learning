#include"Dog.h"

Dog::Dog(std::string dogName)://建構子
    Pet(dogName)
{

}

void Dog::eat()
{
    decreaseHungry(10);
}

std::string Dog::getPetType() const 
{
    return "Dog";
}
