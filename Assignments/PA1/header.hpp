#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "Player.hpp"
#include "Command.hpp"
#include "List.hpp"

using namespace std;

//Function Declarations
        void runApp();
        int menu();
        void display_rules();
        void new_game(Player (&playerList)[100], List<Command>& commands);
        void load_game(Player (&playerList)[100], List<Command>& commands);
        void add_command(List<Command>& commands);
        void remove_command(List<Command>& commands);
        void display_all_commands(const List<Command>& commands);
        void save_and_exit(List<Command>& commands, Player (&playerList)[100]);
        bool load_commands(List<Command>& commands);
        void print_commands(const List<Command>& commands);
        void load_players(Player (&playerList)[100]);
        bool check_player_duplicate(const Player (&playerList)[100], string name);
        bool check_command_duplicate(const List<Command>& commands, const string checkCommand);
        void write_commands(List<Command>& commands);
        void write_players(Player (&playerList)[100]);
        bool add_player(Player (&playerList)[100], Player newPlayer);
        void generateQuestions(int (&questionIndexArr)[], int numCommands, int numQuestions);
        Node<Command>* getCommand(const List<Command>& commands, int listIndex);
        int generateDescriptions(const List<Command>& commands,int correctIndex, int numCommands, int numQuestions);
        int play_game(List<Command>& commands, int &num_Questions, int &points);


#endif