#include "window.hpp"
#include "window.cpp"
#include "sorting.hpp"
#include "sorting.cpp"

int main()
{
    Window window;

    while (window.windowIsOpen()) {
        window.update();
        window.render();
    }

    return 0;
}


