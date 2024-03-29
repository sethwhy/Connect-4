#include <iostream>
#include <vector>
using namespace std;

const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
    
// initialize the game board with empty spaces
void init_board(vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; i++) {
        vector<char> row(COLS, EMPTY);
        board.push_back(row);
    }
}

// display the game board
void display_board(const vector<vector<char>>& board, string board_color) {
    // Set the background color of the console
    const string RESET = "\033[0m";
    if (board_color == "blue") {
        cout << "\033[44m";
    } else if (board_color == "red") {
        cout << "\033[41m";
    } else {
        cout << "\033[47m";
    }
    for (int i = 0; i < ROWS; i++) {
        cout << " | ";
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " | ";
        }
        cout << RESET << "\n";
        if (i < ROWS-1) { // Reset color at the end of each row except the last
            if (board_color == "blue") {
                cout << "\033[44m";
            } else if (board_color == "red") {
                cout << "\033[41m";
            } else {
                cout << "\033[47m";
            }
        }
    }
    for (int i = 1; i <= COLS; i++)
    {
        cout << "   " << i;
    }
    cout << "\n";
    cout << RESET;
}


// check if a player has won the game
bool check_win(const vector<vector<char>>& board, char player) {
    if (connect_3 == false)
    {
        // check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }
    // check vertical
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }
    // check diagonal (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }
    // check diagonal (bottom-left to top-right)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player && board[i-3][j+3] == player) {
                return true;
            }
        }
    }
    return false;
    } else {
        // check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 2; j++) {
            if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player) {
                return true;
            }
        }
    }
    // check vertical
    for (int i = 0; i < ROWS - 2; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player) {
                return true;
            }
        }
    }
    // check diagonal (top-left to bottom-right)
    for (int i = 0; i < ROWS - 2; i++) {
        for (int j = 0; j < COLS - 2; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player) {
                return true;
            }
        }
    }
    // check diagonal (bottom-left to top-right)
    for (int i = 2; i < ROWS; i++) {
        for (int j = 0; j < COLS - 2; j++) {
            if (board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player) {
                return true;
            }
        }
    }
    return false;
    }
}

    
// check if the game is a tie
bool check_tie(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

// get the player's move
int get_move(char player) {
    int col;
    
    if (player == 'X')
    {
        cout << "Player " << player_name << ", enter your move (1-" << COLS << "): ";
    }
    else{
        cout << "Player " << opponent_name << ", enter your move (1-" << COLS << "): ";
    }
    
    
    cin >> col;
    while (cin.fail() || col < 1 || col > COLS) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid move. Enter a column number between 1 and " << COLS << ": ";
        cin >> col;
    }
    return col - 1;
}


// update the game board with the player's move
bool make_move(vector<vector<char>>& board, int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

// count the number of wins for each player
void count_wins(char winner, int& player1_wins, int& player2_wins) {
    if (winner == PLAYER1) {
        player1_wins++;
    } else if (winner == PLAYER2) {
        player2_wins++;
    }
}

void reset_board(vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}