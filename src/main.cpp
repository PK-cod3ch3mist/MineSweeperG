#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create and open a window [used a constructor here]
    // The class is sf::Window and object is window
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    // Create a circle in that window
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Run program as long as the window is open
    while (window.isOpen())
    {
        // Check all the windows events triggered since the last iteration of the loop
        sf::Event event;

        // We use pollEvent which returns true if an event was pending, otherwise false
        while (window.pollEvent(event))
        {
            // If we get an event, we check its type
            // Here we are checking for close window request
            if (event.type == sf::Event::Closed)
                window.close(); // We then close the window [has to be explicit] if such a request is made
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
