#include "Cat.h"
#include "Dog.h"
#include "PetManager.h"


int main ()
{
    PetManager petManager;

    petManager.addPet(std::make_unique<Cat>("Mimi"));
    petManager.addPet(std::make_unique<Dog>("Bobo"));

    petManager.feedPets();
    petManager.getpetStatus();

    return 0;
}