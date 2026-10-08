# Sudoku (console, C)

A console Sudoku game written in C.

- Prints the 9×9 grid in the terminal, with the original clues in a different color.
- The player enters a row, a column and a value to fill a cell, or deletes a value they entered.
- Original clues cannot be changed.
- A move is rejected when the same value is already in that row or column.
- The game ends with a message when every cell is filled.

## Running

Open `project soduko/project soduko.cbp` in Code::Blocks and run it, or compile `main.c` with any C
compiler on Windows (it uses `conio.h`).
