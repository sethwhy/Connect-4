#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <string>
//#include "timer.h"

using namespace std;
static string player_name = "X";
static string opponent_name = "O";
static string board_color;
static int ROWS = 6;
static int COLS = 7;
static bool connect_3 = false;

void slow_down_text(string text){
    for (int i = 0; i <= text[i]; i++) {
        cout.flush();
        cout << text[i];
        // Waits for 50000 microseconds
        usleep(50000);
    }
}

void settings(){
    cout << "\nSETTINGS" << endl;
    cout << "Enter your player name: ";
    cin >> player_name;
    cout << endl;

    cout << "Enter your opponent's name: ";
    cin >> opponent_name;
    cout << endl;

    cout << "Enter the board color: (red, blue, otherwise white): ";
    cin >> board_color;
    cout << endl;

    cout << "Settings saved." << endl;
    cout << endl;
}

void mode_menu(){
    int choice = 0;
    cout << "\nGame Modes:" << endl;
    cout << "1. Connect 3\n" << endl;
    cout << "2. Back to Main menu\n" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    static string connect3_explanation = "In this game mode all the objective now is to get 3 pieces next to or diagonal from each other. \nIn a sense instead, of connecting four, the task is 3 now.";
    static string time_rush_explanation = "In this game mode you will be rushed on the clock. You will get a random amount of time from 3-20 seconds to make a move. \nIf you take up too much time, a random move will be replaced for your turn. Be speedy, when you are done reading answer y. ";

    do {
        switch(choice) {
            case 1:
            char ans2;
            cout << connect3_explanation << endl;
            cout << "\nAre you done reading?" << endl;
            cout << "y or n: ";
            cin >> ans2;
            while (ans2 != 'y'){
                cout << "\nScroll up for Instructions." << endl;
                cout << "Are you finished: " << endl;
                cout << "y or n: ";
                cin >> ans2;
            }
            if (connect_3 == false)
            {
                cout << "Connect 3 mode activated." << endl;
                connect_3 = true;
                cout << endl;
            } else
            {
                cout << "Connect 3 mode deactivated." << endl;
                connect_3 = false;
                cout << endl;
            }
            break;

            case 2:
            cout << "Exiting to main menu..." << endl;
            cout << endl;
            break;
        }
    } while(choice == 1 && choice == 2);
}

void set_board_size()
{
    cout << "\nBoard Size Select:" << endl;
    cout << "Enter the number of rows (6-8): ";
    cin >> ROWS;
    while (cin.fail() || ROWS < 6 || ROWS > 8) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid selection. Enter the number of rows (6-8): ";
        cin >> ROWS;
    }
    cout << "Enter the number of columns (6-8): ";
    cin >> COLS;
    while (cin.fail() || COLS < 6 || COLS > 8) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid selection. Enter the number of columns (6-8): ";
        cin >> COLS;
    }
    cout << endl;

    cout << "Board size selections saved." << endl;
}

void menu(){ 
    string main_menu = "MAIN MENU";
    // Traverse the given string S
    slow_down_text(main_menu);
    cout << endl;
    usleep(75000);

    cout << "\n1. Play against a friend\n" << endl;
    cout << "2. Settings\n" << endl;
    cout << "3. Game modes\n" << endl;
    cout << "4. Quit\n" << endl;

    //Variables for messages
    string local_msg_intro = "You will now play a local game. ";
    
    int exit_num = 0; //1 = Leave loop, 0 = Stay inside
    int choice; //option choice for menu
    int main_again = 0;
    do {
        if(main_again == 1){
            string main_menu = "MAIN MENU";
            // Traverse the given string S
            slow_down_text(main_menu);
            cout << endl;
            usleep(75000);

    cout << "\n1. Play against a friend\n" << endl;
    cout << "2. Settings\n" << endl;
    cout << "3. Game modes\n" << endl;
    cout << "4. Quit\n" << endl;
        }
        choice = 0;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            {
            // Traverse the given string S
            slow_down_text(local_msg_intro);
            cout << endl;
            usleep(65000);
            exit_num = 1;
            // code for playing against friend
            break;
            }
            case 2:
            // code for settings
            set_board_size();
            settings();
            exit_num = 0;
            break;

            case 3:
            // code for game modes
            mode_menu();
            exit_num = 0;
            break;

            case 4:
            

            cout << "\nAre you sure you want to quit?" << endl << "y or n: ";
            char var;
            cin >> var;
            cout << endl;

            while (var != 'y'|| var != 'n'){
                if(var == 'y'){
                    cout << "Thanks for playing Connect 4!" << endl;
                    exit(0);
                }
                if(var == 'n'){
                    exit_num = 0;
                    break;
                } else {
                    cout << "Enter y for Yes, n for No.\n";
                    cout << "y or no: ";
                    cin >> var;
                }
            }
            }
            choice = 0;
            main_again = 1;
        } while (exit_num == 0);
    
    usleep(65000);
}