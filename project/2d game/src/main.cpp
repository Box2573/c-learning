#include<iostream>
#include<SFML/Graphics.hpp>
#include "player/Player.hpp"


int main()
{
    Player player(12.f, 5.f , 75.f, 100.f);

    sf::Clock clock;

    sf::RenderWindow window(
        sf::VideoMode({1280, 720}),
        "吸加加 洨遊戲"
    );

    //暫時的地板
    sf::RectangleShape ground;
    ground.setSize({1280.f, 2.f});
    ground.setPosition({0.f, 600.f});

    window.setFramerateLimit(60);//限制最大FPS避免全力運轉

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();//計算delta time

        // 1. 處理事件
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        player.update(deltaTime);

        //render
        window.clear(sf::Color::Black); // 清空畫面為黑色背景
        player.drawPlayer(window, sf::Color::Blue);
        window.draw(ground);
        window.display();               // 顯示到螢幕上


    }

    return 0;
}
