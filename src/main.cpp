#include "game.h"

using namespace sf;

// Defining some global objects which are essential to the program
RenderWindow window(VideoMode(400, 400), "MineSweeper v2.0", Style::Titlebar | Style::Close);
RectangleShape box1(Vector2f(120.f, 40.f));
RectangleShape box2(Vector2f(120.f, 40.f));
Sprite emoji;

class game_cell cell[10][10];

Text no_mine;

Texture game_texture;

Font font;

void init() {
    if (!font.loadFromFile("../assets/fonts/Audiowide/Audiowide-Regular.ttf"))
    {
        std::cout << "Symbol font not loaded" << std::endl;
    }
    window.setKeyRepeatEnabled(false);
}

void welcome(const Text &text, const RectangleShape &play_button, const Text &play_text, const Text &credit_text) {
    window.draw(text);
    window.draw(play_button);
    window.draw(play_text);
    window.draw(credit_text);
}

int main()
{
    no_mine.setFont(font);
    int state = 0;
    bool initialised = false;
    int rw, cl;
    rw = cl = 0;
    init();

    // Setting up the splash screen/welcome window
    // Start here ...
    Text text("Mine Sweeper v2.0", font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(35.f, 10.f);

    RectangleShape play_button(sf::Vector2f(120.f, 50.f));
    play_button.setPosition(140.f, 100.f);

    Text play_text("PLAY", font, 30);
    play_text.setFillColor(sf::Color::Black);
    play_text.setPosition(155.f, 105.f);

    Text credit_text(" Created by Pratyush Kumar\nSee GitHub page for more info", font, 10);
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
            if (event.type == sf::Event::MouseButtonPressed && state == 0)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if (event.mouseButton.x >= 140 && event.mouseButton.x <= 260 && event.mouseButton.y >= 100 && event.mouseButton.y <= 150)
                    {
                        state = 3;
                        continue;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased && state == 3) {
                state = 1;
                continue;
            }
        }

        if (state == 0) {
            window.clear();
            welcome(text, play_button, play_text, credit_text);
            window.display();
        }

        if (state == 1 || state == 2) {
            if (!initialised) {
                init_game();
                display();
                initialised = true;
                state = 1;
            }
            else {
                if (check_w()){
                    display();
                    state = 2;
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (event.mouseButton.x >= 50 && event.mouseButton.y >= 75 && event.mouseButton.x <= 350 && event.mouseButton.y <= 375 && state != 2) {
                            rw = (int)(((int)(event.mouseButton.x) - 50) / 30);
                            cl = (int)(((int)(event.mouseButton.y) - 75) / 30);
                            if (!check_l(rw, cl)) {
                                reveal(rw, cl, true);
                                display();
                            }
                            else {
                                state = 2;
                            }
                        }
                        if (event.mouseButton.x >= 180 && event.mouseButton.x <= 220 && event.mouseButton.y >= 30 && event.mouseButton.y <= 70 && state == 2) {
                            initialised = false;
                            continue;
                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        if (event.mouseButton.x >= 50 && event.mouseButton.y >= 75 && event.mouseButton.x <= 350 && event.mouseButton.y <= 375) {
                            rw = (int)(((int)(event.mouseButton.x) - 50) / 30);
                            cl = (int)(((int)(event.mouseButton.y) - 75) / 30);
                            cell[rw][cl].s_value = 'P';
                            display();
                        }
                    }
                }
            }
        }
    }

    return 0;
}
