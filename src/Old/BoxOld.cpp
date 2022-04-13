#include "../include/Box.hpp"

namespace Sudoku {
    Box::Box(int n, int x, int y) {
        box = sf::RectangleShape(sf::Vector2f(BOX_DIM, BOX_DIM));
        box.setPosition(sf::Vector2f(x, y));
        box.setFillColor(sf::Color::White);

        num = n;

        hovering = false;
        if (n != 0)
            unChangeable = true;
        else
            unChangeable = false;

        textColor = sf::Color::Black;
        hoverColor = sf::Color::Yellow;
        unchangeableColor = sf::Color{211, 211, 211};
    }

    void Box::draw(sf::RenderWindow& window) {
        window.draw(box);

        sf::Font arial;
        arial.loadFromFile("arial.ttf");

        std::string n;
        if (num == 0) {
            n = "_";
        }
        else {
            n = std::to_string(num);
            unChangeable = true;    
        }

        if (hovering) {
            box.setFillColor(hoverColor);
        } else {
            box.setFillColor(unchangeableColor);
        }
        
        sf::Text number(n, arial, TEXT_SIZE);
        number.setCharacterSize(TEXT_SIZE);
        number.setFillColor(sf::Color::Black);
        number.setStyle(sf::Text::Bold);
        number.setPosition(sf::Vector2f(box.getPosition().x + (BOX_DIM/4), box.getPosition().y - (BOX_DIM/7)));
        window.draw(number);
    }

}