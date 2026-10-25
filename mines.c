#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define MINES 10

typedef struct {
    int isMine;
    int isRevealed;
    int adjacentMines;
} Cell;

// this function is used for the initilization of every board members
void initBoard(Cell board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j].isMine = 0;
            board[i][j].isRevealed = 0;
            board[i][j].adjacentMines = 0;
        }
    }
}
// this function is used for display 9*9 board for playing
void printBoard(Cell board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j].isMine == 1)
                printf("* ");
            else
                printf("%d ", board[i][j].adjacentMines);
        }
        printf("\n");
    }
}

// this function is used for placing 10 random mines using rand and srand.
void placeMines(Cell board[ROWS][COLS])
{
    int placed = 0;
    while (placed < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (board[r][c].isMine == 1)
            continue;

        board[r][c].isMine = 1;
        placed++;
    }
}

int isValid(int r, int c)
{
    if (r < ROWS && c < COLS && c >= 0 && r >= 0)
        return 1;

    else
        return 0;
}

void countAdjacent(Cell board[ROWS][COLS])
{

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j].isMine == 1)
                continue;

            int minesCount = 0;

            for (int mi = -1; mi <= 1; mi++) {
                for (int mj = -1; mj <= 1; mj++) {
                    if (isValid(i + mi, j + mj)) {
                        if (mi == 0 && mj == 0)
                            continue;

                        else if (board[i + mi][j + mj].isMine == 1)
                            minesCount++;
                    }
                }
            }
            board[i][j].adjacentMines = minesCount;
        }
    }
}
void reveal(Cell board[][COLS], int r, int c, int *count)
{
    if (!isValid(r, c)) {
        return;
    }
    if (board[r][c].isRevealed == 1) {
        return;
    } else {
        board[r][c].isRevealed = 1;
        (*count)++;
    }

    if (board[r][c].adjacentMines > 0) {
        return;
    } else {
        for (int mi = -1; mi <= 1; mi++) {
            for (int mj = -1; mj <= 1; mj++) {
                reveal(board, r + mi, c + mj, count);
            }
        }
    }
}

void printPlayerView(Cell board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j].isRevealed == 0) {
                printf("# ");
            } else {
                if (board[i][j].adjacentMines > 0)
                    printf("%d ", board[i][j].adjacentMines);
                else
                    printf(". ");
            }
        }
        printf("\n");
    }
}

int main()
{
    Cell board[ROWS][COLS];
    srand(time(NULL));
    initBoard(board);
    placeMines(board);
    countAdjacent(board);
    // printBoard(board);-> use it when debugging

    int row, col;
    int revealedCount = 0;
    int gameOver = 0;
    while (!gameOver) {
        int result, ch;

        printPlayerView(board);
        printf("Enter rows and columns");
        result = scanf("%d %d", &row, &col);
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        if (result != 2) {
            printf("invalid input\n");
            continue;
        }
        row = row - 1;
        col = col - 1;

        if (!isValid(row, col)) {
            printf("OUT OF RANGE MAX INPUT=%d \n", ROWS);
            continue;
        }
        if (board[row][col].isRevealed == 0) {

            if (board[row][col].isMine == 1) {
                board[row][col].isRevealed = 1;
                printf("Game over\n");
                gameOver = 1;

            } else
                reveal(board, row, col, &revealedCount);

        } else {
            printf("Already revealed\n");
            continue;
        }
        if (revealedCount == (ROWS * COLS - MINES)) {
            printf("winner\n");
            gameOver = 1;
        }
    }
    printBoard(board);
    return 0;
}