#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "sorting.hpp"
#include <tuple>
#include <thread>

class Window {
private:
    sf::RenderWindow *window;
    sf::VideoMode video;
    sf::Event events;
    Sorting vector;
public:
    Window();
    ~Window(){};

    void pollEvent();

    void update();
    void render();

    bool windowIsOpen();
};