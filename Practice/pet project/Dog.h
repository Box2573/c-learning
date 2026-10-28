#pragma once
#include "Pet.h"
#include<string>

class Dog : public Pet
{
    public:
        Dog(std::string dogName);
  
        void eat() override;//宣告這裡要實作Pet的純虛函式
        std::string getPetType() const override;
};