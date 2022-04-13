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

        for (int row = 0; row < BORDER_DIM; row++)
            for (int col = 0; col < BORDER_DIM; col++)
                blocks[row][col].draw(window);
    }

    void World::generate_data() {
        srand((unsigned) time(NULL));
        for (int row = 0; row < BLOCK_DIM; row++) {
            for (int col = 0; col < BLOCK_DIM; col++) {
                std::cout << "ROW: " << row << " COL: " << col << std::endl;
                int nums[DIM*DIM];
                int rows[DIM*DIM];
                int cols[DIM*DIM];

                for (int i = 0; i < (DIM*DIM); i++) {
                    int index = i;
                    int boxIndex = i + ((col + (row*DIM))*(DIM*DIM));
                    if (rand() % 2 == 0)
                        nums[i] = 0;
                    else
                        nums[i] = solution[index];
                    rows[i] = BORDER_DIM * 2 + ((boxIndex % (DIM*DIM)) * (BOX_DIM + BORDER_DIM * 2));
                    cols[i] = BORDER_DIM * 2 + ((boxIndex / (DIM*DIM)) * (BOX_DIM + BORDER_DIM * 2));
                }

                blocks[row][col] = Block(nums, rows, cols);
                if (row == 0 && col == 0)
                    blocks[row][col].set_hover(true, 0, 0);
            }
        }
    }

    void World::right_hover() {
        int prevBlockRow = currentBlockRow;
        int prevBlockCol = currentBlockCol;
        int prevBoxRow = currentBoxRow;
        int prevBoxCol = currentBoxCol;

        if (currentBoxCol + 1 != (DIM*DIM))
            currentBoxCol++;

        blocks[prevBlockRow][prevBlockCol].set_hover(false, prevBoxRow, prevBoxCol);
        blocks[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
    }

    void World::left_hover() {
        int prevBlockRow = currentBlockRow;
        int prevBlockCol = currentBlockCol;
        int prevBoxRow = currentBoxRow;
        int prevBoxCol = currentBoxCol;

        if (currentBoxCol - 1 != -1)
            currentBoxCol--;

        blocks[prevBlockRow][prevBlockCol].set_hover(false, prevBoxRow, prevBoxCol);
        blocks[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
    }

    void World::up_hover() {
        int prevBlockRow = currentBlockRow;
        int prevBlockCol = currentBlockCol;
        int prevBoxRow = currentBoxRow;
        int prevBoxCol = currentBoxCol;

        if (currentBlockCol - 1 != -1)
            currentBlockCol--;

        blocks[prevBlockRow][prevBlockCol].set_hover(false, prevBoxRow, prevBoxCol);
        blocks[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
    }

    void World::down_hover() {
        int prevBlockRow = currentBlockRow;
        int prevBlockCol = currentBlockCol;
        int prevBoxRow = currentBoxRow;
        int prevBoxCol = currentBoxCol;

        if (currentBlockCol + 1 != (DIM*DIM))
            currentBlockCol++;

        blocks[prevBlockRow][prevBlockCol].set_hover(false, prevBoxRow, prevBoxCol);
        blocks[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
    }
}