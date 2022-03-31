#ifndef WORLD_HPP
#define WORLD_HPP

#include <iostream>
#include <random>

#include "Box.hpp"

#define WORLD_DIM 800
#define BORDER_DIM 3


namespace Sudoku {
    class World {
        public:
            // Default Constructor
            World() = default;
            // : gridLength(
            //     ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+BOX_DIM))
            //     *
            //     ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+BOX_DIM))
            // ){
            //     generate_data();
            // }

            // Draw Grid onto Screen
            void draw(sf::RenderWindow&);

        private:
            // Box *grid;
            // int *solution;
            // int gridLength;

            // // Generate Random Grid
            // void generate_data();

            // // Draw Borders
            // void draw_borders(sf::RenderWindow&);

            // // Returns the index with the current coordinates
            // int get_index(int, int);

            // // Return X Coordinate
            // int get_x_coordinate(int);
            
            // // Return Y Coordinate
            // int get_y_coordinate(int);
    };
}

#endif