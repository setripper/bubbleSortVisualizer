#pragma once
#include "window.hpp"
#include <vector>
#include <chrono>
#include <random>

class Sorting {
private:
    int numberOfPillars;
    std::vector<std::tuple<int, sf::RectangleShape>> numbers;
    std::mt19937 gen;
    float screenHeight;
    float screenWidth;
public:
    Sorting();
    ~Sorting(){};
    void initVector();

    // Draw Array
    void drawArray(sf::RenderTarget* window);
    void bubbleSort();
    void swap(bool value);
    

    // Assign Screen Size
    void assignScreenSize(float x, float y);
};