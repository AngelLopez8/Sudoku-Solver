#include "include/Window.hpp"

#define WIDTH 1200
#define HEIGHT 806

int main() {

    // Create Window Instance
    Sudoku::Window window(WIDTH, HEIGHT, "Sudoku Game");

    // Game Loop
    window.Initiate();

    return 0;
}