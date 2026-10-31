#pragma once

class Player
{
    private:
        float x, y, width, height;

        //血量相關
        float health = 5;

        //移動相關
        const float speed = 0.3f;

        //跳躍相關
        const float jumpHeight = 0.5f;
        const float gravity = -9.8f;

    public:
        Player(float x, float y, float w, float h);

        float getHealth() const;
        void jump();
        void move();
        void getAttacked(float damage);





};