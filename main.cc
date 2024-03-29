/*
Driver program for Connect 4
*/
#include "menu.h"
#include "board.cc"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{   
    // Initialize the string
    string start_display = "Hello CS3560, Welcome to Connect Four";
    // Traverse the given string S
    slow_down_text(start_display);
    cout << endl;
    usleep(80000);
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;
    cout << endl;
    usleep(80000);
    char response;
    do {
    menu();
    vector<vector<char>> board;
    init_board(board);
    char player = PLAYER1;
    bool play_again = true;
    int player1_wins = 0, player2_wins = 0;

    while (play_again) {
        bool game_over = false;
        while (!game_over) {
            display_board(board, board_color);
            int col = get_move(player);
            bool valid_move = make_move(board, col, player);
            while (!valid_move) {
                cout << "Column is full. Choose another column." << endl;
                col = get_move(player);
                valid_move = make_move(board, col, player);
            }
            if (check_win(board, player)) {
                if (player == 'X')
                {
                    cout << "Player " << player_name << " wins!" << endl;
                    count_wins(PLAYER1, player1_wins, player2_wins);
                } else
                {
                    cout << "Player " << opponent_name << " wins!" << endl;
                    count_wins(PLAYER2, player1_wins, player2_wins);
                }
                game_over = true;
            } else if (check_tie(board)) {
                cout << "Tie game." << endl;
                game_over = true;
            } else {
                player = (player == PLAYER1) ? PLAYER2 : PLAYER1;
            }
        }
        cout << "Number of wins for " << player_name << ": " << player1_wins << endl;
        cout << "Number of wins for " << opponent_name << ": " << player2_wins << endl;
        cout << "Do you want to play again? (Y/N) ";
        cin >> response;
        cout << endl;
        play_again = (response == 'Y' || response == 'y');
        reset_board(board);
        player = PLAYER1; 
    }
} while (response == 'n' || response == 'N');
    return 0;
}