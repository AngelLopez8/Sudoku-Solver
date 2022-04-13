#include "../include/World.hpp"

namespace Sudoku {
    /**
     * @brief Construct a new World:: World object
     * 
     */
    World::World() {
        currentBlockRow = 0;
        currentBlockCol = 0;
        currentBoxRow = 0;
        currentBoxCol = 0;

        generate_data();
    }

    /**
     * @brief 
     * 
     * @param window 
     */
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
                grid[row][col].draw(window);
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool World::solved() {
        for (int blockRow = 0; blockRow < BLOCK_DIM; blockRow++)
            for (int blockCol = 0; blockCol < BLOCK_DIM; blockCol++)
                for (int boxRow = 0; boxRow < DIM; boxRow++)
                    for (int boxCol = 0; boxCol < DIM; boxCol++)
                        if (grid[blockRow][blockCol].get_value(boxRow, boxCol) != solution[blockRow][blockCol][boxCol + (boxRow*DIM)])
                            return false;
        return true;
    }

    /**
     * @brief 
     * 
     * @param value 
     */
    void World::change_number(int value) {
        grid[currentBlockRow][currentBlockCol].set_value(value, currentBoxRow, currentBoxCol);
    }

    void World::move_left() {
        grid[currentBlockRow][currentBlockCol].set_hover(false, currentBoxRow, currentBoxCol);
        if (currentBoxCol - 1 == -1) {
            if (currentBlockCol - 1 != -1) {
                currentBoxCol = 2;
                currentBlockCol--;
            }
        } else {
            currentBoxCol--;
        }
        grid[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
        // std::cout << "HOVERING: #" << grid[currentBlockRow][currentBlockCol].get_value(currentBoxRow, currentBoxCol) << std::endl;
    }

    void World::move_right() {
        grid[currentBlockRow][currentBlockCol].set_hover(false, currentBoxRow, currentBoxCol);
        if (currentBoxCol + 1 == 3) {
            if (currentBlockCol + 1 != 3) {
                currentBoxCol = 0;
                currentBlockCol++;
            }
        } else {
            currentBoxCol++;
        }
        grid[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
        // std::cout << "HOVERING: #" << grid[currentBlockRow][currentBlockCol].get_value(currentBoxRow, currentBoxCol) << std::endl;
    }

    void World::move_up() {
        grid[currentBlockRow][currentBlockCol].set_hover(false, currentBoxRow, currentBoxCol);
        if (currentBoxRow - 1 == -1) {
            if (currentBlockRow - 1 != -1) {
                currentBoxRow = 2;
                currentBlockRow--;
            }
        } else {
            currentBoxRow--;
        }
        grid[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
        // std::cout << "HOVERING: #" << grid[currentBlockRow][currentBlockCol].get_value(currentBoxRow, currentBoxCol) << std::endl;
    }

    void World::move_down() {
        grid[currentBlockRow][currentBlockCol].set_hover(false, currentBoxRow, currentBoxCol);
        if (currentBoxRow + 1 == 3) {
            if (currentBlockRow + 1 != 3) {
                currentBoxRow = 0;
                currentBlockRow++;
            }
        } else {
            currentBoxRow++;
        }
        grid[currentBlockRow][currentBlockCol].set_hover(true, currentBoxRow, currentBoxCol);
        // std::cout << "HOVERING: #" << grid[currentBlockRow][currentBlockCol].get_value(currentBoxRow, currentBoxCol) << std::endl;
    }

    /**
     * @brief 
     * 
     */
    void World::generate_data() {
        srand((unsigned) time(NULL));
        grid = new Block*[BLOCK_DIM];
        for (int blockRow = 0; blockRow < BLOCK_DIM; blockRow++) {
            grid[blockRow] = new Block[BLOCK_DIM];
            for (int blockCol = 0; blockCol < BLOCK_DIM; blockCol++) {
                int *rows = new int[DIM*DIM];
                int *cols = new int[DIM*DIM];
                int *nums = new int[DIM*DIM];
                for (int boxRow = 0; boxRow < DIM; boxRow++) {
                    for (int boxCol = 0; boxCol < DIM; boxCol++) {
                        // If random number divisible by 0 then set it as 0, else keep current number
                        if (rand() % 2 == 0) nums[boxCol + (boxRow*DIM)] = 0;
                        else nums[boxCol + (boxRow*DIM)] = solution[blockRow][blockCol][boxCol + (boxRow*DIM)];

                        rows[boxCol + (boxRow*DIM)] = (blockRow * 3 * (BOX_DIM + BORDER_DIM * 2)) + ((BORDER_DIM * 2) + (boxRow * (BOX_DIM + (BORDER_DIM * 2))));
                        cols[boxCol + (boxRow*DIM)] = (blockCol * 3 * (BOX_DIM + BORDER_DIM * 2)) + ((BORDER_DIM * 2) + (boxCol * (BOX_DIM + (BORDER_DIM * 2))));
                    }
                }
                grid[blockRow][blockCol] = Block(nums, cols, rows);
            }
        }
        grid[0][0].set_hover(true, 0, 0);
    }
    
    /**
     * @brief Outputs Grid
     * 
     * @param std::ostream& out 
     * @param World World Object 
     * @return std::ostream& Object
     */
    std::ostream& operator<<(std::ostream& out, const World& world) {
        for (int row = 0; row < BLOCK_DIM; row++) {
            for (int col = 0; col < BLOCK_DIM; col++)
                out << world.grid[row][col] << std::endl;
        }
        return out;
    }
}