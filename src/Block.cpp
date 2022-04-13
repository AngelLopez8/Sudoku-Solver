#include "../include/Block.hpp"

namespace Sudoku {
    /**
     * @brief Construct a new Block:: Block object
     * 
     * @param int* List of Numbers 
     */
    Block::Block(int *nums, int *xCoord, int *yCoord) {
        boxes = new Box*[DIM];

        for (int row = 0; row < DIM; row++) {
            boxes[row] = new Box[DIM];
            for (int col = 0; col < DIM; col++) {
                int numsIndex = col + (row * DIM);
                boxes[row][col] = Box(nums[numsIndex], xCoord[numsIndex], yCoord[numsIndex]);
            }
        }
    }

    /**
     * @brief Draws Block onto Screen
     * 
     * @param sf::RenderWindow& Window Object 
     */
    void Block::draw(sf::RenderWindow& window) {
        for (int row = 0; row < DIM; row++)
            for (int col = 0; col < DIM; col++)
                boxes[row][col].draw(window);
    }

    /**
     * @brief Returns Number value of box at given row & col
     * 
     * @param int row 
     * @param int column 
     * @return box number value 
     */
    int Block::get_value(int row, int col) {
        return boxes[row][col].get_value();
    }

    /**
     * @brief Change specific Box Number value to passed in number
     * 
     * @param int new Number value 
     * @param int row 
     * @param int column 
     */
    void Block::set_value(int value, int row, int col) { boxes[row][col].set_value(value); }

    /**
     * @brief Change specific Box Hover Status
     * 
     * @param bool hover status 
     * @param int row 
     * @param int column 
     * @return true | false 
     */
    void Block::set_hover(bool status, int row, int col) { boxes[row][col].set_hovering(status); }

    /**
     * @brief Returns whether number exists in the following block
     * 
     * @param int Number Val 
     * @return true | false 
     */
    bool Block::check_valid_block_entry(int val) {
        for (int row = 0; row < DIM; row++)
            for (int col = 0; col < DIM; col++)
                if (boxes[row][col].get_value() == val)
                    return false;
        return true;
    }

    /**
     * @brief Returns whether number exists at given row
     * 
     * @param int number value 
     * @param int row 
     * @return true | false 
     */
    bool Block::check_valid_row_entry(int val, int row) {
        for (int col = 0; col < DIM; col++)
            if (boxes[row][col].get_value() == val)
                return false;
        return true;
    }

    /**
     * @brief Returns whether number exists at given column
     * 
     * @param int number value 
     * @param int column 
     * @return true | false 
     */
    bool Block::check_valid_col_entry(int val, int col) {
        for (int row = 0; row < DIM; row++)
            if (boxes[row][col].get_value() == val)
                return false;
        return true;
    }


    /**
     * @brief Outputs current Block Object
     * 
     * @param std::ostream& out 
     * @param Block Current Block Object 
     * @return std::ostream& Object
     */
    std::ostream& operator<<(std::ostream& out, const Block& block) {
        for (int r = 0; r < DIM; r++){
            for(int c = 0; c < DIM; c++)
                out << block.boxes[r][c] << " ";
            out << std::endl;
        }
        return out;
    }
}