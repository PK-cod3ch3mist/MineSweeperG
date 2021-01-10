#include "game.h"

using namespace sf;

// Defining some global objects which are essential to the program
// For example, the main window
// And the associated stuff
RenderWindow window(VideoMode(400, 400), "Minesweeper v2.0");

Font font;

void init() {
    if (!font.loadFromFile("../assets/fonts/Audiowide/Audiowide-Regular.ttf"))
    {
        std::cout << "Symbol font not loaded" << std::endl;
    }
}

void welcome(const Text &text, const RectangleShape &play_button, const RectangleShape &score_button, const Text &play_text, const Text &score_text, const Text &credit_text) {
    window.draw(text);
    window.draw(play_button);
    window.draw(score_button);
    window.draw(play_text);
    window.draw(score_text);
    window.draw(credit_text);
}

int main()
{
    init();

    // Setting up the splash screen/welcome window
    // Start here ...
    Text text("Mine Sweeper v2.0", font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(35.f, 10.f);

    RectangleShape play_button(sf::Vector2f(120.f, 50.f));
    play_button.setPosition(140.f, 100.f);

    RectangleShape score_button(sf::Vector2f(160.f, 50.f));
    score_button.setPosition(120.f, 200.f);

    Text play_text("PLAY", font, 30);
    play_text.setFillColor(sf::Color::Black);
    play_text.setPosition(155.f, 105.f);

    Text score_text("SCORES", font, 30);
    score_text.setFillColor(sf::Color::Black);
    score_text.setPosition(130.f, 205.f);

    Text credit_text("created by Ord-Com. MIT license\n see GitHub page for more info", font, 10);
    credit_text.setFillColor(sf::Color::White);
    credit_text.setPosition(100.f, 350.f);
    // End here...
    // The above are definitions required for the welcome window

    // Run program as long as the window is open
    while (window.isOpen())
    {
        // Check all the windows events triggered since the last iteration of the loop
        Event event;

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
        welcome(text, play_button, score_button, play_text, score_text, credit_text);
        window.display();
    }

    return 0;
}
