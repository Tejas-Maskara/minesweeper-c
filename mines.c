#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define ROWS 9
#define COLS 9
#define MINES 10

typedef struct {
    int isMine;
    int isRevealed;
    int adjacentMines;
} Cell;

void initBoard( Cell board[ROWS][COLS]){
    for(int i=0;i<ROWS;i++){
        for (int  j = 0; j < COLS; j++)
        {
            board[i][j].isMine=0;
            board[i][j].isRevealed=0;
            board[i][j].adjacentMines=0;
            /* code */
        }
        
    }
}

void printBoard(Cell board[ROWS][COLS])
{
     for(int i=0;i<ROWS;i++){
        for (int  j = 0; j < COLS; j++)
        {
            if(board[i][j].isMine==1){
                printf("*");

            }
            else
            printf(".");
         
            /* code */
        }
        printf("\n");
        
    }

}

void placeMines(Cell board[ROWS][COLS])
{
    int placed=0;
    while(placed<MINES)
    {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if(board[r][c].isMine==1)
            continue;
        
        board[r][c].isMine=1;
        placed++;

    }

}


int main()
{
    Cell board[ROWS][COLS];
    srand(time(NULL));
    initBoard(board);
    placeMines(board);
    printBoard(board);
    int count = 0;
for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
        if (board[i][j].isMine == 1)
            count++;
printf("\nMines placed: %d\n", count);
    return 0;
}