# MineSweeper v1.5
This is actually an improved GUI version for the CLI minesweeper I made

## Dependencies and Installation
* A C++ compiler, one supporting C++11 would be good. You could install G++/GCC or Clang or MinGW
* SFML libraries/API. For linux users this is easy, simply use your package manager, (for example in Ubuntu)
```shell
sudo apt-get install libsfml-dev
```
for MacOS users I would recommend doing the same using homebrew. 
```shell
brew install sfml
```
For detailed instructions, visit https://www.sfml-dev.org
* For macOS and Linux users, the Makefile will make compilation easy. Simply go to the src folder and type make in the terminal. That should do the job.
## Gameplay
Well it is minesweeper, you will figure it out easily enough. However, here are a few details :
* When you win a game, the smiley at the top shows off ( by wearing shades ). To play again, simply click on the smiley.
* Similarly when you lose, to play again click on the smiley.

### A Small Demo
![A Small Demo](https://drive.google.com/file/d/13OwZfUtZeuVf0WCYiY61SVipoJGoo5uE/view?usp=sharing)

## Features to come
I am currently working upon a highscore collection system and a timing system for the game. This feature will be added soon.
