#include "Player.hpp"
#include<iostream>

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

    void Player::update()
    {
        //jump
        //外面還要先檢查是否按下跳躍鍵
        //判斷是否在地上
        if(isGround())
        {
            //在地上觸發跳躍
           jump();
        }
        else//不在地上，表示在空中一直扣掉重力
        {
            Player::velocityY += Player::gravity;//sfml往下是+y因此+重力
        }
        //更新位置
      
    }

    void Player::jump()
    {
        //jump
        //外面還要先檢查是否按下跳躍鍵
         Player::velocityY = Player::jumpVelocity;
        
    }
    void Player::move()
    {
        //move
    }
    void Player::getAttacked(float damage)
    {
        health -= damage;
    }

    bool Player::isGround()
    {
        //這裡還沒實作先回傳true
        return Player::y + Player::height >= Player::groundY;
    }

    void Player::drawPlayer(sf::RenderWindow& window, sf::Color playerColor) const
    {
        sf::RectangleShape player({Player::width, Player::height});//玩家大小
        player.setFillColor(playerColor);//玩家顏色
        player.setPosition({Player::x, Player::y});//玩家初始位置
        window.draw(player);//繪製出玩家
    }
