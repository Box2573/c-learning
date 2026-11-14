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

    void Player::update(float deltaTime)
    {
        #pragma region Jump
        //jump
        //判斷是否在地上
        if(isGround())
        {
            //避免穿過地板和歸0速度
            Player::y =  Player::groundY -  Player::height;
            Player::velocityY = 0;

            //先檢查是否按下跳躍鍵
            //觸發跳躍
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                std::cout << "Jump!\n";
                jump();
            }
        }
        else//不在地上，表示在空中一直扣掉重力
        {
            //這一幀因為重力而新增的速度 = 加速度 * delta time
            //不乘delta time會導致可能fps很高會導致重力被加很多次
            Player::velocityY += Player::gravity *deltaTime;//sfml往下是+y因此+重力
        }
        //更新位置，這一幀實際上走過的距離 = 速度*delta time
        Player::y += Player::velocityY * deltaTime;
        #pragma endregion

        #pragma region Move
        float horizontal = 0.f;//移動方向
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//按下往左
            horizontal -= 1.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//按下往右
             horizontal += 1.f;

        //現在距離 = 現在距離 + 移動距離，  移動距離 = 方向 * 速度 * 時間
        Player::x += horizontal * Player::moveSpeed * deltaTime;

        #pragma endregion

    }

    void Player::jump()
    {
        //jump
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

    bool Player::isGround() const
    {
        return Player::y + Player::height >= Player::groundY;
    }

    void Player::drawPlayer(sf::RenderWindow& window, sf::Color playerColor) const
    {
        sf::RectangleShape player({Player::width, Player::height});//玩家大小
        player.setFillColor(playerColor);//玩家顏色
        player.setPosition({Player::x, Player::y});//玩家初始位置
        window.draw(player);//繪製出玩家
    }
