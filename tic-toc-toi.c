#include <stdio.h>

// Function to initialize the game board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard(char board[3][3]) {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", i);
        for (int j = 0; j < 3; ++j) {
            printf("%c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  -----\n");
    }
}

// Function to check if the move is valid
int isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Row win
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Column win
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Diagonal win
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Diagonal win

    return 0; // No win
}

// Function to check if the board is full (a tie)
int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return 0; // Board is not full
        }
    }
    return 1; // Board is full
}

int main() {
    char board[3][3];
    int row, col;
    char currentPlayer = 'X';

    initializeBoard(board);

    do {
        // Display the current state of the board
        displayBoard(board);

        // Get the current player's move
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (isValidMove(board, row, col)) {
            // Make the move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // Check if the board is full (tie)
            if (isBoardFull(board)) {
                displayBoard(board);
                printf("It's a tie!\n");
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Try again.\n");
        }

    } while (1);

    return 0;
}
