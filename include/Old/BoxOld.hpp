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

            //
            int get_value() {
                return num;
            }

            void set_value(int n) {
                num = n;
            }

            bool is_hovering() { return hovering; }

            void set_hovering(bool hover) {
                hovering = hover;
            }

            bool is_unchangeable() { return unChangeable; }

            friend std::ostream& operator<<(std::ostream& out, const Box& box) {
                out << box.num;
                return out;
            }

        private:
            int num;
            sf::RectangleShape box;

            bool hovering;
            bool unChangeable;

            sf::Color textColor;
            sf::Color hoverColor;
            sf::Color unchangeableColor;
    };
}

#endif