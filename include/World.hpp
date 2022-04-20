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
            World();

            // Draw Grid onto Screen
            void draw(sf::RenderWindow&);

            // Checks if entry is safe
            bool is_safe(int, int, int, int, int);

            // Solves Sudoku Board
            bool solve(int, int, int, int);

            // Change number of box
            void change_number(int);

            // Handles Grid navigation
            void move_left();
            void move_right();
            void move_up();
            void move_down();

            // Overloaded Output Operator
            friend std::ostream& operator<<(std::ostream&, const World&);
            
            // If Grid is solved
            bool solved;
        private:
            Block **grid;   // Game Grid

            int currentBlockRow, currentBlockCol;   // Current Hovered Block row & col
            int currentBoxRow, currentBoxCol;   // Current Hovered Box row & col

            // Dynamic Array holding sudoku solution
            int solution[BLOCK_DIM][BLOCK_DIM][DIM*DIM] = {
                {
                    {
                        5, 3, 4,
                        6, 7, 2,
                        1, 9, 8
                    }, 
                    {
                        6, 7, 8,
                        1, 9, 5,
                        3, 4, 2
                    },
                    {
                        9, 1, 2,
                        3, 4, 8,
                        5, 6, 7
                    }
                },
                {
                    {
                        8, 5, 9,
                        4, 2, 6,
                        7, 1, 3
                    },
                    {
                        7, 6, 1,
                        8, 5, 3,
                        9, 2, 4
                    },
                    {
                        4, 2, 3,
                        7, 9, 1,
                        8, 5, 6
                    }
                },
                {
                    {
                        9, 6, 1,
                        2, 8, 7,
                        3, 4, 5
                    },
                    {
                        5, 3, 7,
                        4, 1, 9,
                        2, 8, 6
                    },
                    {
                        2, 8, 4,
                        6, 3, 5,
                        1, 7, 9
                    }
                }
            };

            // Generates data for grid
            void generate_data();
    };
}

#endif