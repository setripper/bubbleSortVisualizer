#include "sorting.hpp"

Sorting::Sorting()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen = std::mt19937(seed);
    numberOfPillars = 100;
}

void Sorting::initVector()
{   
    float barWidth = screenWidth / numberOfPillars;

    std::uniform_int_distribution<> range(10, 500);
    sf::RectangleShape pillar;

    for (int i = 0; i < numberOfPillars; i++) {
        int random = range(gen);
        pillar.setFillColor(sf::Color::White);
        pillar.setSize(sf::Vector2f(barWidth - 1, -random));
        pillar.setPosition(i * barWidth, screenHeight);
        numbers.push_back(std::make_tuple(random, pillar));
    }
}

void Sorting::drawArray(sf::RenderTarget* window)
{   
    for (int i = 0; i < numberOfPillars; i++) {
        sf::RectangleShape& pillar = std::get<1>(numbers[i]);
        window->draw(pillar);
    }
}

void Sorting::bubbleSort()
{
    for (int i = 0; i < numberOfPillars; i++) {
        for (int j = i + 1; j < numberOfPillars; j++) {
            int varI = std::get<0>(numbers[i]);
            int varJ = std::get<0>(numbers[j]);
            if (varJ < varI) {
                std::swap(numbers[i], numbers[j]);
                std::cout << "Swapped " << varI << " with " << varJ << "\n";
                sf::Vector2f posI = std::get<1>(numbers[i]).getPosition();
                sf::Vector2f posJ = std::get<1>(numbers[j]).getPosition();
                std::get<1>(numbers[i]).setPosition(posJ);
                std::get<1>(numbers[j]).setPosition(posI);
                break;
            }
        }
    }
}



void Sorting::assignScreenSize(float x, float y)
{
    screenWidth = x;
    screenHeight = y;
}
