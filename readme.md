# Tic-Tac-Toe with Minimax Algorithm

This is a simple Tic-Tac-Toe game implemented in C++ using the Minimax algorithm for the computer's moves.

## Features
- Play against the computer.
- Computer uses the Minimax algorithm to determine the optimal move.
- Simple text-based interface.

## Getting Started

### Prerequisites
- C++ compiler (e.g., g++)

### Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/dhawal-pandya/tic-tac-toe-minimax.git
   cd tic-tac-toe-minimax


2. Compile the code:
   
    ```sh
    g++ -o tictactoe tictactoe.cpp
    ```

### Running the Game
1. Run the executable:

```sh
./tictactoe
```

2. Follow the on-screen instructions to play the game. Enter the row and column numbers (0, 1, or 2) to make your move.

## How to Play
* The game is played on a 3x3 grid.
* You are 'X' (the player), and the computer is 'O'.
* To make a move, enter the row and column index when prompted.
* The game continues until there is a winner or the board is full (resulting in a tie).

### Example

```diff
    Player's turn (enter row and column): 1 1
          |   |  
        --|---|--
          | X |  
        --|---|--
          |   |  
```

### Acknowledgements

Minimax algorithm for implementing an unbeatable AI for the game.