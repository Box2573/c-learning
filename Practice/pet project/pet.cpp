#include"Pet.h"//自己寫的通常用""include，但<>也可以

Pet::Pet(std::string petName): //建構子
    name(petName)//我已經告知這是Pet的建構子所以他知道有name的存在了
    {}

void Pet::decreaseHungry(int value)
{
     if(hungry - value <= 0)
    {
        hungry = 0;//我已經告知這是Pet的函式所以他知道有hungry的存在了因此不用Pet::hungry
    }
    else
    {
        hungry -= value;
    }
}

int Pet::getHungry() const
{
    return hungry;
}

std::string Pet::getName() const
{
    return name;
}