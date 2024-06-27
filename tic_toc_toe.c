#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_SIZE 3  // to define  size of the Tic Tac Toe board
#define BUFFER_SIZE 256  // To define  buffer size for user input

// Function declarations
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
bool playerMove(char board[BOARD_SIZE][BOARD_SIZE], char player);
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player);
bool checkDraw(char board[BOARD_SIZE][BOARD_SIZE]);
void switchPlayer(char *player);
void clearInputBuffer();

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];  // Declare the Tic Tac Toe board
    char currentPlayer = '0';  // Set the initial player to '0'
    bool gameOver = false;  // Boolean to check if the game is over

    initializeBoard(board);  // Initialize of board with empty spaces

    printf("Welcome to Tic Tac Toe!\n\n");

    while (!gameOver) {  // Loop until the game is over
        printBoard(board);  // Print the current state of the board
        if (playerMove(board, currentPlayer)) {  // Get the player's move
            if (checkWin(board, currentPlayer)) {  // Check if the current player has won
                printBoard(board);  // To Print  final state of the board
 printf("Player %c won!\n", currentPlayer);  //  winner announcement
                gameOver = true;  //  flag for  while loop break
                } else if (checkDraw(board)) {  // Check if the game is a draw
                printBoard(board);  // To Print final state of the board
                printf("It's a draw!\n");  // game  draw
                gameOver = true;  //  flag for while loop break
            } else {
                switchPlayer(&currentPlayer);  // Switch to the other player
            }
        } else {
            printf("Invalid move. Please enter row and column (e.g., 1 2).\n");
            clearInputBuffer();  // Clear the input buffer if the move is invalid
        }
    }

    return 0;  // End the program
}

// Initialize the board with empty spaces
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {  // Iterate over each row
        for (int col = 0; col < BOARD_SIZE; ++col) {  // Iterate over each column
            board[row][col] = ' ';  // Setting of  each cell to a space character
        }
    }
}

// Print the current state of the board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {  // Iterate over each row
    for (int col = 0; col < BOARD_SIZE; ++col) {  // Iterate over each column
            printf(" %c ", board[row][col]);  // Print the cell value
            if (col < BOARD_SIZE - 1) printf("|");  // Print column separator
             }
        printf("\n");
        if (row < BOARD_SIZE - 1) {  // Print row separator
            for (int i = 0; i < BOARD_SIZE * 4 - 1; ++i) {
                printf("-");
            }
            printf("\n");
        }
    }
}

// Get the player's move
bool playerMove(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    char input[BUFFER_SIZE];  // Buffer to store the input
    int row, col;  // Variables to store the row and column entered by the player

    printf("Player %c, enter your move (row and column, e.g., 1 2): ", player);
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {  // Get the input
        return false;  // Return false if there's an input error or EOF
    }

    if (sscanf(input, "%d %d", &row, &col) != 2 || row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE) {
        return false;  // Return false if the input format is invalid or out of range
    }

    row--;  // Convert to zero-based index
     col--;  // Convert to zero-based index

    if (board[row][col] == ' ') {  // Check if the cell is empty
        board[row][col] = player;  // Place the player's move
        return true;  // Return true if the move is valid
    }
 

    return false;  // Return false if the cell is not empty
}

// Check if the current player has won
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Check rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  // Check columns
            return true;  // Return true if there's a win
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Check main diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  // Check anti-diagonal
        return true;  // Return true if there's a win
    }

    return false;  // Return false if there's no win
}

// Check if the game is a draw
bool checkDraw(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {  // Iterate over each row
      for (int col = 0; col < BOARD_SIZE; ++col) {  // Iterate over each column
            if (board[row][col] == ' ') {  // Check if there's any empty cell
                return false;  // Return false if there's an empty cell
            }
        }
    }
    return true;  // Return true if there's no empty cell (draw)
    }

// Switch to the other player
void switchPlayer(char *player) {
    if (*player == '0') {  // If the current player is '0'
        *player = '1';  // Switch to '1'
    } else {
        *player = '0';  // Switch to '0'
    }
}

// Clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Read and discard characters until newline or EOF
}
                                     
