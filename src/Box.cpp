#include "../include/Box.hpp"

namespace Sudoku {
    /**
     * @brief Construct a new Box:: Box object
     * 
     * @param int number value 
     * @param int x coordinate 
     * @param int y coordinate 
     */
    Box::Box(int n, int x, int y) :
        num(n), xCoordinate(x), yCoordinate(y), hovering(false)
    {
        box = sf::RectangleShape(sf::Vector2f(BOX_DIM, BOX_DIM));
        box.setPosition(sf::Vector2f(xCoordinate, yCoordinate));
        box.setFillColor(sf::Color::White);
    }

    /**
     * @brief 
     * 
     * @param window 
     */
    void Box::draw(sf::RenderWindow& window) {
        sf::Font arial;
        arial.loadFromFile("arial.ttf");

        std::string value = "_";

        if (num != 0) value = std::to_string(num);

        sf::Text number(value, arial, TEXT_SIZE);
        number.setCharacterSize(TEXT_SIZE);
        
        if (hovering) number.setFillColor(sf::Color::Yellow);
        else number.setFillColor(sf::Color::Black);

        number.setStyle(sf::Text::Bold);
        number.setPosition(box.getPosition().x + (BOX_DIM/4), box.getPosition().y - (BOX_DIM/7));

        window.draw(box);
        window.draw(number);
    }

    /**
     * @brief Returns current Box number
     * 
     * @return box number 
     */
    int Box::get_value() {
        return num;
    }

    /**
     * @brief Sets box number to passed in number
     * 
     * @param int new number value
     */
    void Box::set_value(int n) {
        num = n;
    }

    /**
     * @brief 
     * 
     * @param status 
     */
    void Box::set_hovering(bool status) { hovering = status; }

    /**
     * @brief Outputs current box number
     * 
     * @param std::ostream& out 
     * @param Box Current Box Object
     * @return std::ostream& Object
     */
    std::ostream& operator<<(std::ostream& out, const Box& box) {
        out << box.num;
        return out;
    }
}