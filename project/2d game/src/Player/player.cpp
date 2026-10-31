#include "Player.hpp"

Player::Player(float x, float y, float w, float h):
        x(x),
        y(y),
        width(w),
        height(h)
    {}

    float Player::getHealth() const
    {
        return health;
    }

    void Player::jump()
    {
        //jump
    }
    void Player::move()
    {
        //move
    }
    void Player::getAttacked(float damage)
    {
        health -= damage;
    }
