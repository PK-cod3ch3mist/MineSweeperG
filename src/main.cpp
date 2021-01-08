#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create and open a window [used a constructor here]
    // The class is sf::Window and object is window
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    sf::Font font;
    if (!font.loadFromFile("../fonts/Audiowide/Audiowide-Regular.ttf"))
    {
        std::cout << "Symbol font not loaded" << std::endl;
    }

    sf::Text text("Mine Sweeper v2.0", font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(40.f, 10.f);

    sf::RectangleShape play_button(sf::Vector2f(120.f, 50.f));
    play_button.setPosition(140.f, 100.f);

    sf::RectangleShape score_button(sf::Vector2f(160.f, 50.f));
    score_button.setPosition(120.f, 200.f);

    sf::Text play_text("PLAY", font, 30);
    play_text.setFillColor(sf::Color::Black);
    play_text.setPosition(155.f, 105.f);

    sf::Text score_text("SCORES", font, 30);
    score_text.setFillColor(sf::Color::Black);
    score_text.setPosition(130.f, 205.f);

    sf::Text credit_text("created by Ord-Com. MIT license\n see GitHub page for more info", font, 10);
    credit_text.setFillColor(sf::Color::White);
    credit_text.setPosition(100.f, 350.f);

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
        window.draw(text);
        window.draw(play_button);
        window.draw(play_text);
        window.draw(score_button);
        window.draw(score_text);
        window.draw(credit_text);
        window.display();
    }

    return 0;
}
