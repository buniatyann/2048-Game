//g++ -o 2048 main.cpp GameModel.cpp GameWidget.cpp GameController.cpp -lncurses
#include <iostream>
#include <ncurses.h>
#include "GameModel.h"
#include "GameWidget.h"
#include "GameController.h"

int main() {
    // Prompt the player for the board size
    int boardSize;
    std::cout << "Welcome to 2048!" << std::endl;
    std::cout << "Choose board size (3 to 8): ";
    
    while (true) {
        std::cin >> boardSize;
        if (boardSize >= 3 && boardSize <= 8) {
            break;
        }
        std::cout << "Invalid size. Please enter a number between 3 and 8: ";
    }

    // Initialize the game with the chosen board size
    GameModel model(boardSize);
    GameWidget widget;
    GameController controller(model, widget);

    // Start the game loop
    controller.run();

    return 0;
}

// #include <iostream>
// #include <ncurses.h>
// #include "GameModel.h"
// #include "GameWidget.h"
// #include "GameController.h"

// void showMenu();

// int main() {
//     // Initialize ncurses
//     initscr(); // Start ncurses mode
//     noecho();  // Disable input echo
//     cbreak();  // Disable line buffering

//     showMenu(); // Show the opening menu

//     // Close ncurses mode
//     endwin();

//     return 0;
// }

// void showMenu() {
//     int choice;

//     while (true) {
//         clear(); // Clear the screen

//         printw("Welcome to 2048!\n\n");
//         printw("1. Play\n");
//         printw("2. About\n");
//         printw("3. Exit\n\n");
//         printw("Choose an option: ");
//         refresh(); // Refresh the screen to show updates

//         // Get user input
//         choice = getch();

//         switch(choice) {
//             case 1:
//                 // User chose Play
//                 clear(); // Clear the screen
//                 printw("Starting the game...\n");
//                 refresh();
//                 int boardSize;
//                 printw("Choose board size (3 to 8): ");
//                 refresh();
//                 while (true) {
//                     scanw("%d", &boardSize);
//                     if (boardSize >= 3 && boardSize <= 8) {
//                         break;
//                     }
//                     printw("Invalid size. Please enter a number between 3 and 8: ");
//                     refresh();
//                 }
//                 GameModel model(boardSize);
//                 GameWidget widget;
//                 GameController controller(model, widget);
//                 controller.run();
//                 break;

//             case 2:
//                 // User chose About
//                 clear();
//                 printw("2048 is a puzzle game where you merge tiles to form a tile with the number 2048.\n");
//                 printw("Enjoy the challenge and have fun!\n");
//                 printw("Press any key to return to the main menu.");
//                 refresh();
//                 getch(); // Wait for any key press to return
//                 break;

//             case 3:
//                 // User chose Exit
//                 clear();
//                 printw("Exiting the game. Goodbye!\n");
//                 refresh();
//                 getch(); // Wait for any key press before exiting
//                 return;

//             default:
//                 // Invalid input
//                 clear();
//                 printw("Invalid option. Please choose a valid option.\n");
//                 refresh();
//                 getch();
//                 break;
//         }
//     };
// }
