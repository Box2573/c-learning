#pragma once
#include <string>

class Pet
{
    private:
        int hungry = 50;
        std::string name;

    public:
        virtual ~Pet() = default;
        Pet(std::string petName);


        virtual void eat() = 0;
        virtual std::string getPetType() const = 0;

        void decreaseHungry(int value);
        int getHungry() const;
        std::string getName() const;

};