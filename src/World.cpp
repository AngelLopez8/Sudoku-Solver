#include "../include/World.hpp"

namespace Sudoku {

    void World::draw(sf::RenderWindow& window) {
        sf::RectangleShape bordersV[4];
        
        for (int i = 0; i < 4; i++) {
            int x = (i % 4) * (BOX_DIM + (BORDER_DIM * 2)) * 3;
            int y = 0;

            bordersV[i].setSize(sf::Vector2f(BORDER_DIM * 2, 800));
            bordersV[i].setPosition(sf::Vector2f(x, y));
            bordersV[i].setFillColor(sf::Color::Red);
            window.draw(bordersV[i]);
        }

        sf::RectangleShape bordersH[4];
        
        for (int i = 0; i < 4; i++) {
            int x = 0;
            int y = ((i % 4) * (BOX_DIM + (BORDER_DIM * 2)) * 3);

            bordersH[i].setSize(sf::Vector2f(800, (BORDER_DIM * 2)));
            bordersH[i].setPosition(sf::Vector2f(x, y));
            bordersH[i].setFillColor(sf::Color::Red);
            window.draw(bordersH[i]);
        }

        Box boxes[81];

        for (int i = 0; i < 81; i++) {
            int x = BORDER_DIM * 2 + ((i % 9) * (BOX_DIM + BORDER_DIM * 2));
            int y = BORDER_DIM * 2 + ((i / 9) * (BOX_DIM + BORDER_DIM * 2));

            boxes[i] = Box((i % 9) + 1, x, y);
            boxes[i].draw(window);
        }
    }
}