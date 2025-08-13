#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker;
int currentPlayer;

// Function to display the board
void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to place a marker
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

// Function to check for a win
char checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

    // Check columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return '/'; // No winner yet
}

// Switch player turn
void swapPlayerAndMarker() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    if (currentPlayer == 1) currentPlayer = 2;
    else currentPlayer = 1;
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;

    drawBoard();

    int moves = 0;
    while (true) {
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), choose your slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        drawBoard();
        moves++;

        char winner = checkWinner();
        if (winner == 'X' || winner == 'O') {
            cout << " Player " << currentPlayer << " wins!\n";
            break;
        }

        if (moves == 9) {
            cout << "It's a draw!\n";
            break;
        }

        swapPlayerAndMarker();
    }
}

int main() {
    game();
    return 0;
}
