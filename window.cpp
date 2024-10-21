#include "window.hpp"

Window::Window()
{
    sf::Vector2f screenSize(1280, 720);
    video.width = screenSize.x;
    video.height = screenSize.y;
    window = new sf::RenderWindow(video, "Sorting Algorithm Visualizer");
    window->setFramerateLimit(144);

    vector.assignScreenSize(screenSize.x, screenSize.y);
    vector.initVector();
}

void Window::pollEvent()
{
    while(window->pollEvent(events)) {
        if (events.type == sf::Event::Closed) {
            window->close();
        }
        if (events.key.code == sf::Keyboard::Escape) {
            window->close();
        }
    }
}

void Window::update()
{   
    pollEvent();
    // Perform one iteration of bubble sort
    vector.bubbleSort();
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
}

void Window::render()
{
    window->clear();
    vector.drawArray(window);
    window->display();

}

bool Window::windowIsOpen()
{
    return window->isOpen();
}
