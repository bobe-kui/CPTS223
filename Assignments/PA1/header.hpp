#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include "Player.hpp"

using namespace std;

//Function Declarations
void runApp();
int menu();
void display_rules();
void new_game();
void load_game();
void add_command();
void remove_command();
void display_all_commands();
void save_and_exit();
void load_commands();

void runApp()
{
    int menu_input = 0;
    while(menu_input !=0)
    {
        menu_input = menu();
        switch(menu_input)
        {
        case 1: 
            display_rules();
            break;
        case 2: 
        // new_game();
            break;
        case 3: 
            //load_game();
            break;
        case 4:
            //add_command();
            break;
        case 5:
            //remove_command();
            break;
        case 6:
            //display_all_commands();
            break;
        case 7:
            //save_and_exit();
            break;
        default: 
            cout << "Invalid input" << endl;
            break;
        } 
    }
    
}

int menu() // display menu & get user input
{
    int user_input =0;
    while(user_input > 7 || user_input < 1)
    {
        cout << "Linux Command Match" << endl << endl;
        cout << "1. Game Rules" << endl << "2. New Game" << endl << "3. Load Game" << endl << "4. Add Command" << endl << "5. Remove Command" << endl << "6. Display All Commands" << endl << "7. Save and Exit" << endl;
        cin >> user_input;
        if(user_input > 7 || user_input < 1)
        {
            cout << "Invalid input, enter a number 1-7" << endl; 
        }
    }
    return user_input;
}

void display_rules()
{
    cout << "Game Rules" << endl;
    cout << "1. The game will display a Linux command and the user will have to guess the command's function." << endl;
    cout << "2. The user will be given 3 chances to guess the command's function." << endl;
    cout << "3. The user will be awarded 3 points for a correct guess on the first try, 2 points for a correct guess on the second try, and 1 point for a correct guess on the third try." << endl;
    cout << "4. The user will lose 1 point for an incorrect guess." << endl;
    cout << "5. The game will continue until the user decides to exit." << endl;
    cout << "6. The user will be able to save the game and exit at any time." << endl;
    cout << "7. The user will be able to load a saved game at any time." << endl;
    cout << "8. The user will be able to add commands to the game." << endl;
    cout << "9. The user will be able to remove commands from the game." << endl;
    cout << "10. The user will be able to display all commands." << endl;
    cout << "11. The user will be able to save and exit the game." << endl;
}

void new_game();


#endif