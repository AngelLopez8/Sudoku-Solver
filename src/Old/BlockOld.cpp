#include "../include/Block.hpp"

namespace Sudoku {

    Block::Block(int nums[], int xCoords[], int yCoords[]) {
        blockSize = DIM*DIM;
        for (int row = 0; row < DIM; row++)
            for (int col = 0; col < DIM; col++) {
                boxes[row][col] = Box(
                    nums[col + (row * DIM)],
                    xCoords[col + (row * DIM)],
                    yCoords[col + (row * DIM)]
                );
            }
    }

    void Block::draw(sf::RenderWindow& window) {
        for (int row = 0; row < DIM; row++){
            for (int col = 0; col < DIM; col++){
                // std::cout << boxes[row][col].get_value() << " ";
                boxes[row][col].draw(window);
            }
            // std::cout << std::endl;    
        }
    } 
    
    bool Block::check_invalid_number_row(int num, int row) {
        for (int i = 0; i < DIM; i++) {
            if (boxes[row][i].get_value() == num) {
                return false;
            }
        }
        return true;
    }

    bool Block::check_invalid_number_col(int num, int col) {
        for (int i = 0; i < DIM; i++) {
            if (boxes[i][col].get_value() == num) {
                return false;
            }
        }
        return true;
    }

    bool Block::check_invalid_number_block(int num) {
        for (int row = 0; row < DIM; row++)
            for (int col = 0; col < DIM; col++)
                if (boxes[row][col].get_value() == num)
                    return false;
        return true;
    }
}