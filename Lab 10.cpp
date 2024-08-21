/*
Luke Rogers
CSE 130 - Section 1
Lab 10 - 3D TicTacToe
4/2/2024
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class ThreeDTicTacToe {
protected:
    char board[3][3][3];    //3-d array for board positions, [layers][rows][columns]
    char currentPlayer;	    //computer (O) or player (X)
    bool gameOver;		    //variable for checking if the game ends

public:
    ThreeDTicTacToe() {	//constructor
    //initialize board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    board[i][j][k] = ' ';
                }
            }
        }
        //randomly choose who goes first
        srand(time(0));
        currentPlayer = (rand() % 2 == 0) ? 'X' : 'O';
        gameOver = false;
    }

    void makeBoard() {
        //make the board display
        //layer 1
        cout << "   Layer 1\n";
        cout << "  1   2   3\n";
        cout << "1 " << board[0][0][0] << " | " << board[0][0][1] << " | " << board[0][0][2] << endl;
        cout << "  ---------" << endl;
        cout << "2 " << board[0][1][0] << " | " << board[0][1][1] << " | " << board[0][1][2] << endl;
        cout << "  ---------" << endl;
        cout << "3 " << board[0][2][0] << " | " << board[0][2][1] << " | " << board[0][2][2] << endl;

        //layer 2
        cout << "               Layer 2\n";
        cout << "              1   2   3\n";
        cout << "            1 " << board[1][0][0] << " | " << board[1][0][1] << " | " << board[1][0][2] << endl;
        cout << "              ---------" << endl;
        cout << "            2 " << board[1][1][0] << " | " << board[1][1][1] << " | " << board[1][1][2] << endl;
        cout << "              ---------" << endl;
        cout << "            3 " << board[1][2][0] << " | " << board[1][2][1] << " | " << board[1][2][2] << endl;

        //layer 3
        cout << "                           Layer 3\n";
        cout << "                          1   2   3\n";
        cout << "                        1 " << board[2][0][0] << " | " << board[2][0][1] << " | " << board[2][0][2] << endl;
        cout << "                          ---------" << endl;
        cout << "                        2 " << board[2][1][0] << " | " << board[2][1][1] << " | " << board[2][1][2] << endl;
        cout << "                          ---------" << endl;
        cout << "                        3 " << board[2][2][0] << " | " << board[2][2][1] << " | " << board[2][2][2] << endl;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool isValidMove(int layer, int row, int col) { //confirm move was valid
        return (layer >= 1 && layer <= 3 && row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[layer - 1][row - 1][col - 1] == ' ');
    }

    bool checkWin() {
        //check for 3 in a row
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                    
                    //rows/columns on a single layer
                if ((board[i][j][0] == currentPlayer && board[i][j][1] == currentPlayer && board[i][j][2] == currentPlayer) ||
                    (board[i][0][j] == currentPlayer && board[i][1][j] == currentPlayer && board[i][2][j] == currentPlayer) ||
                    //diagonals on a single layer
                    (board[i][0][0] == currentPlayer && board[i][1][1] == currentPlayer && board[i][2][2] == currentPlayer) ||
                    (board[i][0][2] == currentPlayer && board[i][1][1] == currentPlayer && board[i][2][0] == currentPlayer) ||
                    //vertically through layers
                    (board[0][i][j] == currentPlayer && board[1][i][j] == currentPlayer && board[2][i][j] == currentPlayer) ||
                    //diagonal across rows and through layers
                    (board[0][i][0] == currentPlayer && board[1][i][1] == currentPlayer && board[2][i][2] == currentPlayer) ||
                    (board[0][i][2] == currentPlayer && board[1][i][1] == currentPlayer && board[2][i][0] == currentPlayer) ||
                    //diagonal across columns and through layers
                    (board[0][0][i] == currentPlayer && board[1][1][i] == currentPlayer && board[2][2][i] == currentPlayer) ||
                    (board[0][2][i] == currentPlayer && board[1][1][i] == currentPlayer && board[2][0][i] == currentPlayer) ||
                    //diagonals through all
                    (board[0][0][0] == currentPlayer && board[1][1][1] == currentPlayer && board[2][2][2] == currentPlayer) ||
                    (board[0][0][2] == currentPlayer && board[1][1][1] == currentPlayer && board[2][2][0] == currentPlayer) || 
                    (board[0][2][0] == currentPlayer && board[1][1][1] == currentPlayer && board[2][0][2] == currentPlayer) ||
                    (board[0][2][2] == currentPlayer && board[1][1][1] == currentPlayer && board[2][0][0] == currentPlayer)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isBoardFull() {
        //check if the board is full which would be a draw
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (board[i][j][k] == ' ') {
                        return false;
                    }
                }
            }
        }
        return true;
    }  
};

class Play3D_TTT : public ThreeDTicTacToe{
public:
    void play() {
        int layer, row, col;

        while (!gameOver) {     //ensure game stops
            makeBoard();
            if (currentPlayer == 'X') {
                //player's turn
                cout << "Player's (X) turn. Enter layer, row and column (1-3): ";
                cin >> layer >> row >> col;
            }
            else {
                //computer's turn
                layer = (rand() % 3) + 1;
                row = (rand() % 3) + 1;
                col = (rand() % 3) + 1;
                cout << "Computer's (O) turn: " << layer << " " << row << " " << col << endl;
            }

            if (isValidMove(layer, row, col)) {    //make sure move is valid
                board[layer - 1][row - 1][col - 1] = currentPlayer;
                if (checkWin()) {   //check if move causes a win
                    makeBoard();
                    if (currentPlayer == 'X')
                        cout << "Player (X) wins!" << endl;
                    else
                        cout << "Computer (O) wins!" << endl;
                    gameOver = true;
                }
                else if (isBoardFull()) { //check if move causes draw
                    makeBoard();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                }
                else {    //switch turns
                    switchPlayer();
                }
            }
            else {    //retry after invalid move
                cout << "Invalid move. Please try again." << endl;
            }
        }
    }
};

int main() {
    Play3D_TTT game;
    game.play();
    return 0;
}
