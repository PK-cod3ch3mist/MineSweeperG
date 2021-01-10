#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <iostream>

// Already set difficulty level at medium

sf::Texture game_texture;

class game_cell {
    private:
        int row;
        int col;
        int size;

    public:
        int b_value;
        int s_value;
        sf::Sprite scell;

        game_cell() {
            b_value = 0;
            s_value = '.';
            row = 0;
            col = 0;
            size = 30;
            scell.setTexture(game_texture);
            scell.setTextureRect(sf::IntRect(10, 10, 30, 30));
        }

        void set_pos(int r, int c) {
            row = r;
            col = c;
            r = 50 + (size * row);
            c = 75 + (size * col);
            scell.setPosition(sf::Vector2f(r, c));
        }
};

sf::RectangleShape box1(sf::Vector2f(120.f, 40.f));
sf::RectangleShape box2(sf::Vector2f(120.f, 40.f));

// To set up the grid and mines
void init();

// The main play function
void reveal();

// Draw the items to the board
void display();

// Check if game is won
void check();
