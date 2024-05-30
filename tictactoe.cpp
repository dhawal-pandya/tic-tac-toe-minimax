#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

const char PLAYER = 'X';
const char COMPUTER = 'O';
const char EMPTY = ' ';

void printBoard(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;
    }
}

bool isMovesLeft(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == EMPTY)
                return true;
    return false;
}

int evaluate(const vector<vector<char> >& b) {
    // Checking for Rows for X or O victory.
    for (int row = 0; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == PLAYER)
                return +10;
            else if (b[row][0] == COMPUTER)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == PLAYER)
                return +10;
            else if (b[0][col] == COMPUTER)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == PLAYER)
            return +10;
        else if (b[0][0] == COMPUTER)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == PLAYER)
            return +10;
        else if (b[0][2] == COMPUTER)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}

int minimax(vector<vector<char> >& board, int depth, bool isMax) {
    int score = evaluate(board);

    // If Maximizer has won the game return evaluated score
    if (score == 10)
        return score - depth;

    // If Minimizer has won the game return evaluated score
    if (score == -10)
        return score + depth;

    // If there are no more moves and no winner then it is a tie
    if (!isMovesLeft(board))
        return 0;

    // If this maximizer's move
    if (isMax) {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Check if cell is empty
                if (board[i][j] == EMPTY) {
                    // Make the move
                    board[i][j] = PLAYER;

                    // Call minimax recursively and choose the maximum value
                    best = max(best, minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
    // If this minimizer's move
    else {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Check if cell is empty
                if (board[i][j] == EMPTY) {
                    // Make the move
                    board[i][j] = COMPUTER;

                    // Call minimax recursively and choose the minimum value
                    best = min(best, minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

pair<int, int> findBestMove(vector<vector<char> >& board) {
    int bestVal = 1000;
    pair<int, int> bestMove = make_pair(-1, -1);

    // Traverse all cells, evaluate minimax function for all empty cells. Return the cell with optimal value.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                int moveVal = minimax(board, 0, true);
                board[i][j] = EMPTY;
                if (moveVal < bestVal) {
                    bestMove = make_pair(i, j);
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, EMPTY));
    int row, col;
    printBoard(board);

    while (true) {
        cout << "Player's turn (enter row and column): ";
        cin >> row >> col;
        if (board[row][col] != EMPTY) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        board[row][col] = PLAYER;

        if (evaluate(board) == 10) {
            printBoard(board);
            cout << "Player wins!" << endl; // will never happen
            break;
        }
        if (!isMovesLeft(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        pair<int, int> bestMove = findBestMove(board);
        board[bestMove.first][bestMove.second] = COMPUTER;

        if (evaluate(board) == -10) {
            printBoard(board);
            cout << "Computer wins!" << endl;
            break;
        }
        if (!isMovesLeft(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }
        printBoard(board);
    }
    return 0;
}
