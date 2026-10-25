# Minesweeper in C

## Overview

A terminal Minesweeper: 9×9 board, with 10 mines.

## Build and Run

For compilation:

```
gcc -Wall mines.c -o mines
```

For execution:

```
.\mines.exe
```

## Playing Rules

Input your desired value of Row and Column from 1 to 9.

| Symbol | Meaning |
|---|---|
| `#` | non revealed cell |
| `.` | revealed cell and a non mine cell |
| `*` | revealed mine cell |

Numbers shown in the grid represent the amount of mines in their 8 neighbouring cells, selecting a non mine will open their neighbours till it encounters mines.

## Win Condition

- Pop out all the non mine cells to win.
- If a mine is popped you lose.

## Sample Output

```
# # # # # # # # # 
# # # # # # # # # 
# # # # # # # # # 
# # # # # # # # # 
# # # # # # # # # 
# # # # # # # # # 
# # # # # # # # # 
# # # # # # # # # 
# # # # # # # # # 
Enter rows and columns 4 5
. . . . . 1 # # # 
1 2 2 1 . 1 # # # 
# # # 1 . 1 2 3 2 
# # 3 1 . . . . . 
# # 1 . . . . . . 
# # 1 . . . . . . 
# # 1 1 1 . . . . 
# # # # 2 1 . . . 
# # # # # 1 . . . 
Enter rows and columns 3 2
Game over
0 0 0 0 0 1 2 3 2 
1 2 2 1 0 1 * * * 
1 * * 1 0 1 2 3 2 
3 4 3 1 0 0 0 0 0 
* * 1 0 0 0 0 0 0 
* 3 1 0 0 0 0 0 0 
1 1 1 1 1 0 0 0 0 
0 0 1 * 2 1 0 0 0 
0 0 1 2 * 1 0 0 0 
```

## What I Learned

- I learned how memory system work
- How scanf operate
- Learned about buffer
- Learned how games are developed in phases and debugged
