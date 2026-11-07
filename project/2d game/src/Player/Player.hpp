#pragma once
#include<SFML/Graphics.hpp>


class Player
{
    private:
        float x, y, width, height;

        //血量相關
        float health = 5;

        //移動相關
        const float speed = 0.3f;

        //跳躍相關
        const float jumpVelocity = -700.f;//sfml y朝上是負的
        const float gravity = 2000.f;
        
        float velocityY = 0.f;

        //地板高度
        const float groundY = 600.f;

    public:
        Player(float x, float y, float w, float h);

        float getHealth() const;
        void getAttacked(float damage);

        //movement
        void jump();
        void move();
        
        //physics
        bool isGround() const;
        void update(float deltaTime);

        //render
        void drawPlayer(sf::RenderWindow& window, sf::Color playerColor) const;





};