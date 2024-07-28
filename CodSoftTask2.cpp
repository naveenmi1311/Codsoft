#include <iostream>
#include <vector>
#include <limits> // For std::numeric_limits

using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  0   1   2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << ' ';
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "  ---------\n";
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to reset the board
void resetBoard(vector<vector<char>>& board) {
    for (auto& row : board) {
        fill(row.begin(), row.end(), ' ');
    }
}

// Function to handle player input
bool getPlayerMove(int& row, int& col, char player) {
    cout << "Player " << player << ", enter your move (row and column numbers, 0-2): ";
    cin >> row >> col;

    // Check for valid input
    if (cin.fail() || row < 0 || row > 2 || col < 0 || col > 2) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid move, try again.\n";
        return false;
    }
    return true;
}

int main() {
    char playAgain = 'y';

    while (playAgain == 'y') {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';

        while (true) {
            displayBoard(board);
            int row, col;

            // Handle invalid moves and prompt until a valid move is made
            while (true) {
                if (getPlayerMove(row, col, currentPlayer)) {
                    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                        break; // Valid move
                    }
                    cout << "Invalid move, try again.\n";
                }
            }

            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer
    }

    return 0;
}
