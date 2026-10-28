#pragma once
#include "Pet.h"
#include<string>

class Cat : public Pet
{
    public:
        Cat(std::string catName);
  
        void eat() override;//宣告這裡要實作Pet的純虛函式
        std::string getPetType() const override;
};