#include <iostream>
#include <string>
#include<memory>


#pragma region attack behaviour 
class Attack
{
    public:
        virtual ~Attack() = default;
        virtual void attackBehaviour() = 0;
};

class Magic : public Attack
{
    public:
        void attackBehaviour() override
        {
            std::cout << " Magic Attack. \n";
        }
};

class Bow : public Attack
{
    public:
        void attackBehaviour() override
        {
            std::cout << " Bow Attack. \n";
        }
};

class Sword : public Attack
{
    public:
        void attackBehaviour() override
        {
            std::cout << " Sword Attack. \n";
        }
};

#pragma endregion

#pragma region characters
class Character
{
    private:
        std::unique_ptr<Attack> attack;
        std::string name;

    public:
         Character(std::unique_ptr<Attack> attackMethod, std::string name):
            attack(std::move(attackMethod)),
            name(name)
        {
           
        }

        void curAttack() const 
        {
            std::cout << name << "attacks!\n" ;
            attack -> attackBehaviour();
        }

        void setAttack(std::unique_ptr<Attack> attackMethod)
        {
           attack = std::move(attackMethod);
        }
};

#pragma endregion

int main()
{

    Character warrior(std::make_unique<Sword>(), "warrior");//建立動態 Sword 物件，由 unique_ptr<Attack> 管理
    Character mage(std::make_unique<Magic>(), "mage");
    Character archer(std::make_unique<Bow>(), "archer");

    warrior.curAttack();
    mage.curAttack();
    archer.curAttack();

    warrior.setAttack(std::make_unique<Magic>());
    warrior.curAttack();
    mage.curAttack();

    return 0;
}