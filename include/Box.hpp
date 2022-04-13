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

            // Return current value
            int get_value();

            // Change value
            void set_value(int);

            // Set hovering status
            void set_hovering(bool);

            // Overloaded Output Operator
            friend std::ostream& operator<<(std::ostream&, const Box&);

        private:
            int num;    // Current Box Number
            int xCoordinate, yCoordinate;   // Coordinates of box

            sf::RectangleShape box; // Box object
            bool hovering;  // hovering status
    };
}

#endif