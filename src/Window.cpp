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
        ) {
        world = World();
    }

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
                    paused = !paused;
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
    }

    /**
     * @brief Handles Render Cycle
     * 
     */
    void Window::render() {
        world.draw(*this);
    }
}