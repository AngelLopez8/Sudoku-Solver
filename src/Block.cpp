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
     * @brief 
     * 
     * @param window 
     */
    void Block::draw(sf::RenderWindow& window) {
        for (int row = 0; row < DIM; row++)
            for (int col = 0; col < DIM; col++)
                boxes[row][col].draw(window);
    }

    /**
     * @brief 
     * 
     * @param row 
     * @param col 
     * @return int 
     */
    int Block::get_value(int row, int col) {
        return boxes[row][col].get_value();
    }

    /**
     * @brief 
     * 
     * @param value 
     * @param row 
     * @param col 
     */
    void Block::set_value(int value, int row, int col) { boxes[row][col].set_value(value); }

    /**
     * @brief 
     * 
     * @param status 
     * @param row 
     * @param col 
     * @return true 
     * @return false 
     */
    void Block::set_hover(bool status, int row, int col) { boxes[row][col].set_hovering(status); }

    /**
     * @brief 
     * 
     * @param val 
     * @return true 
     * @return false 
     */
    bool Block::check_valid_block_entry(int val) {
        for (int row = 0; row < DIM; row++)
            for (int col = 0; col < DIM; col++)
                if (boxes[row][col].get_value() == val)
                    return false;
        return true;
    }

    /**
     * @brief 
     * 
     * @param val 
     * @param row 
     * @return true 
     * @return false 
     */
    bool Block::check_valid_row_entry(int val, int row) {
        for (int col = 0; col < DIM; col++)
            if (boxes[row][col].get_value() == val)
                return false;
        return true;
    }

    /**
     * @brief 
     * 
     * @param val 
     * @param col 
     * @return true 
     * @return false 
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