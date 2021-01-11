#include "game.h"

void init_game() {
    if (!game_texture.loadFromFile("../assets/images/classic.png")) {
        std::cout << "texture not loaded successfully. Abort...";
    }

    // Set the row and col number and hence the positions of the cells
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cell[i][j].set_pos(i, j);
        }
    }
    
    // Set the position of the boxes and other passive elements
    box1.setPosition(sf::Vector2f(55.f, 30.f));
    box2.setPosition(sf::Vector2f(225.f, 30.f));

    emoji.setTexture(game_texture);
    emoji.setTextureRect(sf::IntRect(0, 24, 26, 26));
    emoji.setScale(sf::Vector2f(1.54f, 1.54f));
    emoji.setPosition(180.f, 30.f);

    // Finally, assign value to b_value and s_value;
    // Using a preiously defined algorithm in CLI version
    //
    // Set number of mines
    int num_mine = 15 + rand()%5;
    std::string num_mine_str = std::to_string(num_mine);
    no_mine.setString(num_mine_str);
    no_mine.setCharacterSize(32);
    no_mine.setFillColor(sf::Color::Red);
    no_mine.setPosition(100.f, 30.f);

    // Set their positions on the grid
    int pos_col, pos_row;
    pos_col = pos_row = 0;
    for (int i = 0; i < num_mine; i++) {
        pos_row = rand()%10;
        pos_col = rand()%10;
        cell[pos_row][pos_col].b_value = -1;
    }

    // Set up the rest of the values
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (cell[i][j].b_value != -1) {
                if (cell[i-1][j].b_value == -1 && (i-1)>=0) ++flag;
                if (cell[i+1][j].b_value == -1 && (i+1)<10) ++flag;
                if (cell[i][j-1].b_value == -1 && (j-1)>=0) ++flag;
                if (cell[i][j+1].b_value == -1 && (i+1)<10) ++flag;
                if (cell[i+1][j+1].b_value == -1 && (i+1)<10 && (j+1)<10) ++flag;
                if (cell[i+1][j-1].b_value == -1 && (i+1)<10 && (j-1)>=0) ++flag;
                if (cell[i-1][j+1].b_value == -1 && (i-1)>=0 && (j+1)<10) ++flag;
                if (cell[i-1][j-1].b_value == -1 && (i-1)>=0 && (j+1)>=0) ++flag;
                cell[i][j].b_value = flag;
            }
            flag = 0;
        }
    }

    // Drawing the starting stuff
    window.clear();
    window.draw(box1);
    window.draw(box2);
    window.draw(emoji);
    window.draw(no_mine);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j){
            window.draw(cell[i][j].scell);
        }
    }
    window.display();
}

void reveal(int rw, int cl, bool select) {
    if (cell[rw][cl].s_value != '.' && cell[rw][cl].s_value != 'P') {
        return;
    }

    if (rw >= 10 || rw < 0 || cl >= 10 || cl < 0) {
        return;
    }

    if (select == false) {
        // If discovered cell is a number, then return
        if (cell[rw][cl].b_value > 0) {
            cell[rw][cl].s_value = (char)(48 + cell[rw][cl].b_value);
            return;
        }

        // If discovered cell is empty, find the ones adjacent to it
        else if (cell[rw][cl].b_value == 0) {
            cell[rw][cl].s_value = '_';
            reveal(rw, cl - 1, 0);
            reveal(rw, cl + 1, 0);
            reveal(rw - 1, cl, 0);
            reveal(rw + 1, cl, 0);
            reveal(rw + 1, cl + 1, 0);
            reveal(rw + 1, cl - 1, 0);
            reveal(rw - 1, cl + 1, 0);
            reveal(rw - 1, cl - 1, 0);
        }
    }

    // If it was selected cell, proceed as follows
    else {
        if (cell[rw][cl].b_value == 0) {
            cell[rw][cl].s_value = '_';
            reveal(rw, cl - 1, 0);
            reveal(rw, cl + 1, 0);
            reveal(rw - 1, cl, 0);
            reveal(rw + 1, cl, 0);
            reveal(rw + 1, cl + 1, 0);
            reveal(rw + 1, cl - 1, 0);
            reveal(rw - 1, cl + 1, 0);
            reveal(rw - 1, cl - 1, 0); 
        }

        else if (cell[rw][cl].b_value > 0)
            cell[rw][cl].s_value = 48 + cell[rw][cl].b_value;
    }

    // In all other cases, return
    return;
}

// The display function, responsible for the graphics seen
void display() {
    window.clear();
    window.draw(box1);
    window.draw(box2);
    window.draw(emoji);
    window.draw(no_mine);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            switch(cell[i][j].s_value) {
                case '.' : cell[i][j].scell.setTextureRect(sf::IntRect(0, 51, 16, 16)); break;
                case 'P' : cell[i][j].scell.setTextureRect(sf::IntRect(34, 51, 16, 16)); break;
                case '_' : cell[i][j].scell.setTextureRect(sf::IntRect(17, 51, 16, 16)); break;
                case '1' : cell[i][j].scell.setTextureRect(sf::IntRect(0, 68, 16, 16)); break;
                case '2' : cell[i][j].scell.setTextureRect(sf::IntRect(17, 68, 16, 16)); break;
                case '3' : cell[i][j].scell.setTextureRect(sf::IntRect(34, 68, 16, 16)); break;
                case '4' : cell[i][j].scell.setTextureRect(sf::IntRect(51, 68, 16, 16)); break;
                case '5' : cell[i][j].scell.setTextureRect(sf::IntRect(68, 68, 16, 16)); break;
                case '6' : cell[i][j].scell.setTextureRect(sf::IntRect(85, 68, 16, 16)); break;
                case '7' : cell[i][j].scell.setTextureRect(sf::IntRect(102, 68, 16, 16)); break;
                case '8' : cell[i][j].scell.setTextureRect(sf::IntRect(119, 68, 16,16)); break;
            }
            window.draw(cell[i][j].scell);
        }        
    }
    window.display();
}

bool check_l(int rw, int cl) {
    if (cell[rw][cl].b_value == -1) {
        // Initiate the game lost sequence XD
        emoji.setTextureRect(sf::IntRect(108, 24, 26, 26));
        window.clear();
        window.draw(box1);
        window.draw(box2);
        window.draw(emoji);
        window.draw(no_mine);
        // Simple, display all the mines in the grid
        // And for the ones marked by flags, display a crossed sign over them
        cell[rw][cl].scell.setTextureRect(sf::IntRect(102, 51, 16, 16));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (!(i == rw && j == cl)){
                    if (cell[i][j].b_value == -1) {
                        if (cell[i][j].s_value == 'P') {
                            cell[i][j].scell.setTextureRect(sf::IntRect(119, 51, 16, 16));
                        }
                        else if (cell[i][j].s_value == '.') {
                            cell[i][j].scell.setTextureRect(sf::IntRect(85, 51, 16, 16));
                        }
                    }
                }
                window.draw(cell[i][j].scell);
            }
        }
        window.display();
        return true;
    }
    else {
        return false;
    }
}

bool check_w() {
    int check = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (cell[i][j].s_value == '.' && cell[i][j].b_value != -1) {
                check = 0;
                break;
            }
        }
    }
    if (check) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (cell[i][j].b_value != -1 && (cell[i][j].s_value == 'P' || cell[i][j].s_value == '.')) {
                    check = 0;
                }
            }
        }
        if (check) {
            std::cout << "YOU WIN !!";
            return true;
        }
    }
    return false;
}
