#include<iostream>
#include<SFML/Graphics.hpp>
#include"Player.hpp"


int main()
{
    Player player(0.f, 0.f , 100.f, 100.f);

    sf::RenderWindow window(
        sf::VideoMode({1280, 720}),
        "C++ Sandbox"
    );

    while (window.isOpen())
    {
        // 1. 處理事件
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

    }

    return 0;
}
