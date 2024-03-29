#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Box.hpp"

#define DIM 3

namespace Sudoku {
    class Block {
        public:
            // Default Constructor
            Block() = default;

            // Overloaded Constructor
            Block(int*, int*, int*);

            // Draw Block onto Screen
            void draw(sf::RenderWindow&);

            // Return value at given coordinate
            int get_value(int, int);

            // Change box number value
            void set_value(int, int, int);

            // Change hovering status of Box
            void set_hover(bool, int, int);

            // Check if number exists in block
            bool check_valid_block_entry(int);

            // Check if number exists in specific row
            bool check_valid_row_entry(int, int);

            // Check if number exists in specific col
            bool check_valid_col_entry(int, int);

            // Overloaded Output Operator
            friend std::ostream& operator<<(std::ostream&, const Block&);

        private:
            Box **boxes;    // Dynamic Array of boxes
    };
}

#endif