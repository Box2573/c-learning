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
        const float jumpVelocity = 0.5f;
        const float gravity = 9.8f;
        
        float velocityY = 0.f;

        //地板高度
        const float groundY = 600.f;

    public:
        Player(float x, float y, float w, float h);

        float getHealth() const;
        void jump();
        void move();
        void getAttacked(float damage);
        bool isGround();
        void update();
        void drawPlayer(sf::RenderWindow& window, sf::Color playerColor) const;





};