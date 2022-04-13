#ifndef WORLD_HPP
#define WORLD_HPP

#include <iostream>
#include <random>

#include "Block.hpp"

#define WORLD_DIM 800
#define BORDER_DIM 3
#define BLOCK_DIM 3


namespace Sudoku {
    class World {
        public:
            // Default Constructor
            World() {
                generate_data();
                currentBlockRow = 0;
                currentBlockCol = 0;
                currentBoxRow = 0;
                currentBoxCol = 0;
            }

            // Draw Grid onto Screen
            void draw(sf::RenderWindow&);

            void right_hover();

            void left_hover();

            void up_hover();

            void down_hover();

            void change_number(int num) {
                blocks[currentBlockRow][currentBlockCol].set_value(num, currentBoxRow, currentBoxCol);
            }

            friend std::ostream& operator<<(std::ostream& out, const World& world) {
                for (int r = 0; r < BLOCK_DIM; r++) {
                    for (int c = 0; c < BLOCK_DIM; c++)
                        out << blocks[r][c];
                }
                return out;
            }
            
        private:
            Block blocks[BLOCK_DIM][BLOCK_DIM];
            int solution[(BLOCK_DIM*BLOCK_DIM)*(DIM*DIM)] = {
                5, 3, 4, 6, 7, 8, 9, 1, 2,
                6, 7, 2, 1, 9, 5, 3, 4, 8,
                1, 9, 8, 3, 4, 2, 5, 6, 7,
                8, 5, 9, 7, 6, 1, 4, 2, 3,
                4, 2, 6, 8, 5, 3, 7, 9, 1,
                7, 1, 3, 9, 2, 4, 8, 5, 6,
                9, 6, 1, 5, 3, 7, 2, 8, 4,
                2, 8, 7, 4, 1, 9, 6, 3, 5,
                3, 4, 5, 2, 8, 6, 1, 7, 9
            };

            int currentBlockRow, currentBlockCol;
            int currentBoxRow, currentBoxCol;

            void generate_data();
    };
}

#endif