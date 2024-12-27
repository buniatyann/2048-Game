# 2048 Console Game
This is a console-based implementation of the 2048 game, using the MVC (Model-View-Controller) design pattern. The game is built in C++ and uses the ncurses library for handling terminal UI.

## Game Overview:
2048 is a sliding puzzle game where the objective is to combine tiles with the same number to form larger numbers, ultimately trying to reach the 2048 tile.

## Features
1. MVC design pattern: The game logic (Model), user interface (View), and user interactions (Controller) are separated.
2. ncurses for terminal-based UI: The game is played directly in the terminal using the ncurses library.
3. Smooth controls with keyboard input.
4. Game over when no more valid moves are available.

## Files Structure:
```
/2048-console-game
│
├── src/
│   ├── GameModel.h          # Header file for the GameModel class (Game Logic)
│   ├── GameModel.cpp        # Implementation of GameModel class
│   ├── GameWidget.h         # Header file for the GameWidget class (View)
│   ├── GameWidget.cpp       # Implementation of GameWidget class
│   ├── GameController.h     # Header file for the GameController class (Controller)
│   ├── GameController.cpp   # Implementation of GameController class
│   └── main.cpp             # Entry point of the game
│
├── Makefile                 # Makefile for building the game
├── README.md               # This readme file
└── LICENSE                  # Game license
```
