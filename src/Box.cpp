#include "../include/Box.hpp"

namespace Sudoku {
    Box::Box(int n, int x, int y) {
        box = sf::RectangleShape(sf::Vector2f(BOX_DIM, BOX_DIM));
        box.setPosition(sf::Vector2f(x, y));
        box.setFillColor(sf::Color::White);

        num = n;
    }

    void Box::draw(sf::RenderWindow& window) {
        window.draw(box);

        sf::Font arial;
        arial.loadFromFile("arial.ttf");

        sf::Text number(std::to_string(num), arial, TEXT_SIZE);
        number.setCharacterSize(TEXT_SIZE);
        number.setFillColor(sf::Color::Black);
        number.setStyle(sf::Text::Bold);
        number.setPosition(sf::Vector2f(box.getPosition().x + (BOX_DIM/4), box.getPosition().y - (BOX_DIM/7)));
        window.draw(number);
    }

}