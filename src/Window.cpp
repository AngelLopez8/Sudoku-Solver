#include "../include/Window.hpp"

namespace Sudoku {

    /**
     * @brief Construct a new Window object
     * 
     * @param int Window width 
     * @param int Window height 
     * @param string title 
     */
    Window::Window(int width, int height, std::string title) : 
        sf::RenderWindow(
            sf::VideoMode(width, height), 
            title, 
            sf::Uint32(sf::Style::Titlebar | sf::Style::Close)
        ) {}

    /**
     * @brief Runs Game Loop
     * 
     */
    void Window::Initiate () {
        while (isOpen()) {
            // Handle Events
            event_handle();

            // Update Cycle
            if (!paused)
                update();

            // Render Cycle
            clear(sf::Color::Black);    // Clear previous Scene

            render();   // Draw current Scene
            
            display();  // Displays Scene
        }
    }

    /**
     * @brief Handles Window Events
     * 
     */
    void Window::event_handle() {
        sf::Event event;

        while (pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                close();
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space)
                    std::cout << world;
                if (event.key.code == sf::Keyboard::Enter) {
                    std::cout << world.solve(0, 0, 0, 0) << std::endl;
                    world.solved = true;
                }
                if (event.key.code == sf::Keyboard::Up)
                    world.move_up();
                if (event.key.code == sf::Keyboard::Down)
                    world.move_down();
                if (event.key.code == sf::Keyboard::Right)
                    world.move_right();
                if (event.key.code == sf::Keyboard::Left)
                    world.move_left();
                if (event.key.code == sf::Keyboard::Num1)
                    world.change_number(1);
                else if (event.key.code == sf::Keyboard::Num2)
                    world.change_number(2);
                else if (event.key.code == sf::Keyboard::Num3)
                    world.change_number(3);
                else if (event.key.code == sf::Keyboard::Num4)
                    world.change_number(4);
                else if (event.key.code == sf::Keyboard::Num5)
                    world.change_number(5);
                else if (event.key.code == sf::Keyboard::Num6)
                    world.change_number(6);
                else if (event.key.code == sf::Keyboard::Num7)
                    world.change_number(7);
                else if (event.key.code == sf::Keyboard::Num8)
                    world.change_number(8);
                else if (event.key.code == sf::Keyboard::Num9)
                    world.change_number(9);
                break;
            default:
                break;
            }
        }
    }

    /**
     * @brief Handles Update Cycle
     * 
     */
    void Window::update() {
        if (world.solved) {
        }
    }

    /**
     * @brief Handles Render Cycle
     * 
     */
    void Window::render() {
        world.draw(*this);
    }
}