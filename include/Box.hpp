#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#define BOX_DIM 83
#define TEXT_SIZE 80

namespace Sudoku {
    class Box {
        public:
            // Default Constructor
            Box() = default;

            // Overloaded Constructor (number, x coordinate, y coordinate)
            Box(int, int, int);
            
            // Draw Box onto Screen
            void draw(sf::RenderWindow&);

        private:
            int num;
            sf::RectangleShape box;
    };
}

#endif