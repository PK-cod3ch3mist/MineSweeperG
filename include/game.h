#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

extern sf::RenderWindow window;
// Already set difficulty level at medium

extern sf::Texture game_texture;

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
            scell.setTextureRect(sf::IntRect(0, 51, 16, 16));
            scell.setScale(sf::Vector2f(1.875f, 1.875f));
        }

        void set_pos(int r, int c) {
            row = r;
            col = c;
            r = 50 + (size * row);
            c = 75 + (size * col);
            scell.setPosition(sf::Vector2f(r, c));
        }

        int get_row() {
            return row;
        }

        int get_col() {
            return col;
        }
};

extern class game_cell cell[10][10];

extern sf::RectangleShape box1;
extern sf::RectangleShape box2;
extern sf::Sprite emoji;

extern sf::Text no_mine;
// To set up the grid and mines
void init_game();

// The main play function
void reveal(int, int, bool);

// Draw the items to the board
void display();

// Check if game is won
bool check_w();

// Check if game is lost
bool check_l(int, int);
