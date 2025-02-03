#include <iostream>
#include <fstream>
#include "header.hpp"
using namespace std;
void runApp()
{

    Player playerList[100]; //List of players/previous games
    List<Command> commands = List<Command>(); //List of all game commands
    
    load_commands(commands); //Load commands from commands.csv
    load_players(playerList); //Load players from players.csv

    int menu_input = 0;
    while(menu_input !=7)
    {
        menu_input = menu();
        switch(menu_input)
        {
        case 1: 
            display_rules();
            break;
        case 2: 
            new_game(playerList, commands);
            break;
        case 3: 
            load_game(playerList, commands);
            break;
        case 4:
            add_command(commands);
            break;
        case 5:
            remove_command(commands);
            break;
        case 6:
            display_all_commands(commands);
            break;
        case 7:
            save_and_exit(commands, playerList);
            cout << "Saving and Exiting Game" << endl;
            
            break;
        default: 
            cout << "Invalid input" << endl;
            break;
        } 
        
    }
    
}

// display menu & get user input
int menu() 
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

//Prints all the rules
void display_rules()
{
    cout << "Game Rules" << endl;
    cout << "1. The game will display a Linux command and the user will have to guess the command's function." << endl;
    cout << "2. The user will be given 3 descriptions to choose from." << endl;
    cout << "3. The user will be awarded points for correct answers." << endl;
    cout << "4. The user will lose 1 point for an incorrect guess." << endl;
    cout << "5. The game will continue until the user decides to exit or the set question limit is hit" << endl;
    cout << "6. The user will be able to save the game and exit at any time." << endl;
    cout << "7. The user will be able to load a saved game at any time." << endl;
    cout << "8. The user will be able to add commands to the game." << endl;
    cout << "9. The user will be able to remove commands from the game." << endl;
    cout << "10. The user will be able to display all commands." << endl;
    cout << "11. The user will be able to save and exit the game." << endl;
}

//Loads commands from commands.csv
bool load_commands(List<Command>& commands)
{
    ifstream infile("commands.csv", ios::in);
    //List<Command> commands;
    if (!infile)
    {
        cout << "Error opening file" << endl;
        return false;
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    string  newLine = "";
    string command = "";
    string description = "";
    int points = 0;
    while(getline(infile, newLine, ','))
    {
        command = newLine;
        if (!getline(infile, newLine, ',')) break;
        description = newLine;
        if (!getline(infile, newLine, '\n')) break;
        try {
            points = stoi(newLine);
        } catch (const invalid_argument& e) {
            cerr << "Invalid points value: " << newLine << endl;
            continue;
        }
        Command newCommand(command, description, points);
        cout << "Command class created" << endl;
        commands.insertFront(newCommand);
        cout << "Command added to list" << endl;
        
    }
    infile.close();
    cout <<"File closed" << endl;
    //print_commands(commands);
    return true;

}

//Prints all commands
void display_all_commands(const List<Command>& commands)
{
        cout << "All Commands" << endl;
        cout << "Command - Description - Points" << endl;
        cout << commands << endl;
}

// Checked to see if commands are loaded correctly
void load_players(Player (&playerList)[100])
{
    ifstream infile("profiles.csv", ios::in);
    if (!infile)
    {
        cout << "Error opening file" << endl;
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    string  newLine = "";
    string name = "";
    int points = 0;
    int questions =0;
    int i =0;
    while(getline(infile, newLine, ','))
    {
        name = newLine;
        if (!getline(infile, newLine, ',')) break;
        try {
            points = stoi(newLine);
        } catch (const invalid_argument& e) {
            cerr << "Invalid points value: " << newLine << endl;
            continue;
        }
        if (!getline(infile, newLine, '\n')) break;
        try {
            questions = stoi(newLine);
        } catch (const invalid_argument& e) {
            cerr << "Invalid points value: " << newLine << endl;
            continue;
        }
        Player newPlayer(name, points, questions);
        playerList[i] = newPlayer;
        i++;
       
    }
        cout << playerList[i] << endl;
}

void generateQuestions(int (&questionIndexArr)[], int numCommands, int numQuestions)
{
    int A = 7;
    int M = numCommands+1;
    srand((unsigned)time(0));
    questionIndexArr[0] = (rand()%numCommands);
    for(int i =1; i < numQuestions; i++)
    {
        while(questionIndexArr[i] == questionIndexArr[i-1])
        {
        questionIndexArr[i] = (rand()%numCommands);
        }
        
    }
    //random number generator
}

Node<Command>* getCommand(const List<Command>& commands, int listIndex)
{
    Node<Command>* pCurrent = commands.getHead();
    for(int i=0; i < listIndex; i++)
    {
        pCurrent = pCurrent->getNext();
    }
    return pCurrent;
}

int generateDescriptions(const List<Command>& commands,int correctIndex, int numCommands, int numQuestions)
{
    //generate a random number 1 -3
    int caseNum = 0;
    int userInput=0;
    srand((unsigned)time(0));
    caseNum = (rand()%3)+1;
    int wrongAnswer1 = 0;
    int wrongAnswer2 = 0;
    do
    {
        wrongAnswer1 = (rand()%numCommands);
    }while(wrongAnswer1 == correctIndex);
    do
    {
        wrongAnswer2 = (rand()%numCommands);
    } while (wrongAnswer2 == correctIndex || wrongAnswer2 == wrongAnswer1);
    
    switch(caseNum)
    {
        case 1:
            cout << "1. " << getCommand(commands, correctIndex)->getData().getDescription() << endl;
            cout << "2. " << getCommand(commands, wrongAnswer1)->getData().getDescription() << endl;
            cout << "3. " << getCommand(commands, wrongAnswer2)->getData().getDescription() << endl;
            cout << "4. Save and exit" << endl;
            break;
        case 2:
            cout << "1. " << getCommand(commands, wrongAnswer1)->getData().getDescription() << endl;
            cout << "2. " << getCommand(commands, correctIndex)->getData().getDescription() << endl;
            cout << "3. " << getCommand(commands, wrongAnswer2)->getData().getDescription() << endl; 
            cout << "4. Save and exit" << endl;
            break;
        case 3:
            cout << "1. " << getCommand(commands, wrongAnswer1)->getData().getDescription() << endl;
            cout << "2. " << getCommand(commands, wrongAnswer2)->getData().getDescription() << endl;
            cout << "3. " << getCommand(commands, correctIndex)->getData().getDescription() << endl; 
            cout << "4. Save and exit" << endl;
            break;
    }
    cin >> userInput;
    if(userInput == 4)
    {
        return -1;
    }
    if(userInput == caseNum)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void new_game(Player (&playerList)[100], List<Command>& commands)
{
    string playerName = "";
    bool playerExists = false;
    int points = 0;
    int num_Questions = 0;
    int questionIndex = 0;
    int result =0;


    while(playerExists == false)
    {
        cout << "New Game" << endl;
        cout << "Enter your name: ";
        cin >> playerName;
        if(check_player_duplicate(playerList, playerName) == true)
        {
            cout << "Player already exists, please enter a new name" << endl;
        }
        else
        {
            cout << "Enter desired # of questions: ";
            cin >> num_Questions;
            Player player(playerName, 0, num_Questions);
            result = play_game(commands, num_Questions, points);
            player.setPoints(points);
            player.setQuestions(num_Questions);
            add_player(playerList, player);

            if(result == 0)
            {
                break;
            }
            else{
                cout << "Game Over" << endl;
                cout << "Final Score: " << points << endl;
                break;
            }

            

        }
    }



}

int play_game(List<Command>& commands, int &num_Questions, int &points)
{
    int result =0;
    int questionIndex = 0;
    int num_Commands = 0;
    commands.listLength(commands.getHead(), num_Commands);
    int questionIndexArr[num_Questions] = {0};
    generateQuestions(questionIndexArr, num_Commands, num_Questions);
    while(num_Questions > 0)
    {
        cout << "Questions left: " << num_Questions << endl << endl;
        cout <<"Command: " << getCommand(commands, questionIndexArr[questionIndex])->getData().getCommand() << endl << endl;
        result = generateDescriptions(commands, questionIndexArr[questionIndex], num_Commands, num_Questions);
        switch(result)
        {
            case -1: 
                break;
            case 0: 
                cout << "Incorrect -1" << endl;
                points --;
                num_Questions--;
                questionIndex++;
                break;
            case 1:
                cout << "Correct +" << getCommand(commands, questionIndexArr[questionIndex])->getData().getPoints() << " points" << endl;
                points = points + getCommand(commands, questionIndexArr[questionIndex])->getData().getPoints();
                num_Questions--;
                questionIndex++;
                break;
        }
        if(result == -1)
        {
            cout << "Exiting game" << endl;
            return 0;
        }
    }
    return 1;
}

bool add_player(Player (&playerList)[100], Player newPlayer)
{
    int i =0;
    while(playerList[i].getName() != "")
    {
        i++;
        if(i > 100)
        {
            return false;
        }
    }
    playerList[i].setName(newPlayer.getName());
    playerList[i].setPoints(newPlayer.getPoints());
    playerList[i].setQuestions(newPlayer.getQuestions());
    return true;
}

bool check_player_duplicate(const Player (&playerList)[100], string name)
{
    int i =0;
    for (i = 0; i < 100; i++)
    {
        if(playerList[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

bool check_command_duplicate(const List<Command>& commands, const string checkCommand)
{
    Node<Command>* p_Current;
    p_Current = commands.getHead();
    while(p_Current != nullptr)
    {
        if(p_Current->getData().getCommand() == checkCommand)
        {
            return true;
        }
        p_Current = p_Current->getNext();
    }
    return false;
}

void remove_command(List<Command>& commands)
{
    string remCommand = "";
    bool matchCheck = false;
    Node<Command>* pCurrent;
    display_all_commands(commands);
    cout << "Enter the command you would like to delete: ";
    cin >> remCommand;
    matchCheck = check_command_duplicate(commands, remCommand);
    if (matchCheck == true)
    {
        pCurrent = commands.getHead();
        while(pCurrent->getData().getCommand()!= remCommand)
        {
            pCurrent = pCurrent->getNext();
            if(pCurrent == nullptr)
            {
                cout << "Command not found" << endl;
            }
        }
        commands.removeNode(pCurrent->getData());        
    }
    else
    {
        cout << remCommand << "Command not found" << endl;
    }
    
}

void add_command(List<Command> &commands)
{
    string newCommand = "";
    string newDescription = "";
    int newPoints = 0;
    bool matchCheck = false;
    cout << "Enter a new command: " ;
    cin >> newCommand;
    matchCheck = check_command_duplicate(commands, newCommand);        
    if(matchCheck == true)
    {
        cout << "Command already exists..." << endl;
    }
    else
    {
        cout << "Enter a new description: ";
        cin >> newDescription;
        cout << "Enter a point value: ";
        cin >> newPoints;
        Command addCommand(newCommand, newDescription, newPoints);
        commands.insertBack(addCommand);    
    }
    
}

void write_commands(List<Command>& commands)
{
    ofstream outfile("commands.csv", ios::out);
    string write_Command = "";
    string write_Description = "";
    int write_Points = 0;
    Node<Command>* p_Current = commands.getHead();
    if(!outfile)
    {
        cout << "Failed to open file" << endl;
    }
    else
    {
        while(p_Current != nullptr)
        {
            outfile << p_Current->getData().getCommand() << "," << p_Current->getData().getDescription() << "," << p_Current->getData().getPoints() << endl;
            p_Current = p_Current->getNext();
        }   
    }
    outfile.close();
}

void write_players(Player (&playerList)[100])
{
    ofstream outfile("profiles.csv", ios::out);
    string write_Name = "";
    int write_Points = 0;
    int i =0;
    if(!outfile)
    {
        cout << "Failed to open file" << endl;
    }
    else
    {
        for(i = 0; i < 99; i++)
        {
            if(playerList[i].getName() == "")
            {
                outfile.close();
                return;
            }
            outfile << playerList[i].getName() << "," << playerList[i].getPoints() << "," << playerList[i].getQuestions() << endl;
        }   
    }
    outfile.close();
}

void save_and_exit(List<Command>& commands, Player (&playerList)[100])
{
    write_commands(commands);
    write_players(playerList);
}

void load_game(Player (&playerList)[100], List<Command>& commands)
{
    int i = 0;
    int profileInt = 0;
    int result =0;
    cout << "Saved Profiles" << endl;
    while(playerList[i].getName() != "" && i < 100)
    {
        cout << i+1 << "." << playerList[i] << endl;
        i++;
    }
    cout << "Pick your profile: ";
    cin >> profileInt;
    profileInt --;
    int questions = playerList[profileInt].getQuestions();
    int points = playerList[profileInt].getPoints();
    if(questions == 0)
    {
        cout << "Enter new desired # of questions: ";
        cin >> questions;
    }
    result = play_game(commands, questions, points);
    playerList[profileInt].setPoints(points);
    playerList[profileInt].setQuestions(questions);
    if(result == 1)
    {
        cout << "Game Over" << endl;
        cout << "Final Score: " << points << endl;
    }

}