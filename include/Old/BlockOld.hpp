#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Box.hpp"

#define DIM 3

namespace Sudoku {
    class Block {
        public:
            Block() = default;

            Block(int [], int[], int[]);

            void draw(sf::RenderWindow&);

            void set_hover(bool val, int row, int col) {
                boxes[row][col].set_hovering(val);
            }

            int get_number(int row, int col) {
                return boxes[row][col].get_value(); 
            }

            void set_value(int num, int row, int col) {
                boxes[row][col].set_value(num);
            }

            bool check_invalid_number_row(int, int);

            bool check_invalid_number_col(int, int);

            bool check_invalid_number_block(int);

            int get_size() { return blockSize; }

            void print() {
                for (int i = 0; i < DIM; i++) {
                    for (int j = 0; j < DIM; j++) {
                        std::cout << boxes[i][j].get_value() << " ";
                    }
                    std::cout << std::endl;
                }
            }

            friend std::ostream& operator<<(std::ostream& out, const Block& block) {
                for (int r = 0; r < DIM; r++){
                    for(int c = 0; c < DIM; c++)
                        out << block.boxes[r][c] << " ";
                    out << std::endl;
                }
                return out;
            }

        private:
            Box boxes[DIM][DIM];
            int blockSize;
    };
}

#endif