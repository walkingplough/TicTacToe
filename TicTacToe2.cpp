// TicTacToe2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
using namespace std;

int main() {
    char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int r = -1;
    int c = -1;
    char winner = ' ';

    for (int i = 0; i < 9; i++) {
        // print game board
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' ') {
            break;
        }

        // get player input
        cout << "Current Player is " << currentPlayer << endl;
        while (true) {
            cout << "Enter coordinates between 0-2 for row and column (example: 2 1): ";
            cin >> r >> c;
            if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Invalid input, Try again." << endl;
            }
            else if (board[r][c] != ' ') {
                cout << "Tile is full, try again." << endl;
            }
            else {
                break;
            }
            r = -1;
            c = -1;
            cin.clear(); // clear errors
            cin.ignore(10000, '\n');
        }
        board[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // check winner

        // rows - horizontal
        for (int row = 0; row < 3; row++) {
            if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                winner = board[row][0];
                break;
            }
        }
        // columns - vertical
        for (int col = 0; col < 3; col++) {
            if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                winner = board[0][col];
                break;
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }
    }
    if (winner != ' ') {
        cout << "Player " << winner << " has won!!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }
}