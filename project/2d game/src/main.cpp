#include<iostream>
#include<SFML/Graphics.hpp>
#include "player/Player.hpp"


int main()
{
    Player player(12.f, 5.f , 100.f, 100.f);

    sf::RenderWindow window(
        sf::VideoMode({1280, 720}),
        "C++ Sandbox"
    );

    while (window.isOpen())
    {
        player.update();

        // 1. 處理事件
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black); // 清空畫面為黑色背景
        player.drawPlayer(window, sf::Color::Blue);
        window.display();               // 顯示到螢幕上

    }

    return 0;
}
