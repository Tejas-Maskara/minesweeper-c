#include<stdio.h>
#include<stdlib.h>

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


int main()
{ 
    Cell board[ROWS][COLS];
    initBoard(board);
    printBoard(board);
    return 0;

}