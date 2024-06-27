# TIC_TOC_TOE
To compile and run your Tic Tac Toe program in C, you can follow these steps. Let's assume your source code file is named tic_tac_toe.c.

Compilation Steps:
Open Terminal/Command Prompt:

Navigate to the directory where tic_tac_toe.c file is located.
Compile the Program:

Use the gcc compiler (assuming you have GCC installed, which is common on Unix-like systems and can be installed on Windows with MinGW or Cygwin).

gcc tic_tac_toe.c
Execution:
Run the Program:

After successfully compiling, you can run the program directly from the command line:

./a.out
This command executes the compiled tic_tac_toe program, starting your Tic Tac Toe game.


Following these steps should allow us to compile and run your Tic Tac Toe game effectively on your system.




Project Overview:
This project implements a command-line based Tic Tac Toe game in C. It allows two players to take turns placing their marks ('0' and '1') on a 3x3 board until one player wins or the game ends in a draw.




Description of the Game Rules:
Objective: The objective of Tic Tac Toe is to be the first player to get three of your marks ('X' or 'O') in a row, column, or diagonal on the 3x3 board.

Players: Two players take turns marking empty cells on the board.

Gameplay:

Players choose their marks ('0' for Player 1 and '1' for Player 2).
Players alternate turns, placing their marks on an empty cell of the board.
The game continues until one player achieves a winning combination of three marks in a row, column, or diagonal, or until the board is full without a winner (resulting in a draw).
Additional Notes or Known Issues:

Input Validation: The program validates user input for moves. It prompts players to enter row and column numbers (e.g., 1 2) and ensures the input is within valid range (1 to 3).

Buffer Handling: A function (clearInputBuffer) clears the input buffer to handle invalid inputs gracefully.

Platform Compatibility: The program is designed for Unix-like systems (Linux, macOS) and can be adapted for Windows with appropriate adjustments to compilation and clearing the input buffer.

Enhancements: Future enhancements could include implementing a graphical user interface (GUI), adding AI for a single-player mode, or extending the board size for a more challenging game.

This overview provides a clear set of instructions for compiling, running, and understanding your Tic Tac Toe game project in C. Adjustments can be made based on specific requirements or preferences for your project documentation.





