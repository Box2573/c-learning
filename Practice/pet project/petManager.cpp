#include "PetManager.h"
#include <limits>
#include <iostream>

void PetManager::showPetList()
{
    for(std::size_t i = 0; i < pets.size(); i++)
    {
        std::cout << i << ". " << pets[i] -> getPetType() << " " << pets[i] -> getName() << " 目前飢餓值: " <<  pets[i] -> getHungry() << "\n";
    }

    std::cout << "請輸入餵食哪一隻動物: "<< "\n";
}

 int PetManager::readPetID()
{
    int petID;

    showPetList();

    while (true)
    {
        std::cin >> petID;

        if(std::cin && petID >= 0 && static_cast<size_t>(petID) < pets.size())//如果輸入型態正確、範圍正常
        {
            break;//跳出迴圈
        }

        //如果失敗
        std::cout<<"輸入無效！請重新輸入一個數字: \n";
        showPetList();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    return petID;
}

void PetManager::addPet(std::unique_ptr<Pet> pet)
{
    pets.push_back(std::move(pet));//所有權現在在pet上要放到vector只能用move
}

void PetManager::getpetStatus() const
{
    for(const auto &pet : pets)
    {
        std::cout << "寵物名稱: " << pet -> getName() <<" 飢餓值:  " << pet -> getHungry() << "\n"; 
    }
}

void PetManager::feedPets()
{
    int petId;

    if(pets.empty())//先判斷vector是否為空
    {
        std::cout << "目前沒動物\n";
        return;
    }
    
    petId = readPetID();
    pets[petId] -> eat();
    std::cout <<"已餵食: " << pets[petId] -> getPetType() << " " << pets[petId] -> getName() << "\n";
}
