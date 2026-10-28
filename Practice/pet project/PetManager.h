#pragma once

#include <vector>
#include <memory>
#include "Pet.h"

class PetManager//用來管理寵物
{
    private:
        std::vector<std::unique_ptr<Pet>> pets;

        void showPetList();
        int readPetID();

        public:
            void addPet(std::unique_ptr<Pet> pet);
            void getpetStatus() const;
            void feedPets();

};