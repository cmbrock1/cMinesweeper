#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "scanner.h"
#include "game.h"
#include "io.h"
#define MINE '*'
#define COVERED '#'
#define UNCOVERED '_'
char ** 
makeEmptyBoard(char **board,int rows,int cols)
    {
    int r,c;
        board = allocate(sizeof(char *) * rows);
        //allocate the rows of a board
    for (r = 0; r < rows; ++r)
        {
        //allocate the columns of a board
        board[r] = allocate(sizeof(char) * cols);  
        for (c = 0; c < cols; ++c)              //fill the coordinates
            {
            if(r==0)
            board[r][c] = '0' + c;
            else if(c==0)
            board[r][c] = '0' + r;
            else
            board[r][c] = '0';
            }
        }
    return board;        
    }
char **
placeMines(int rows, int cols, int bombs, char **boardWithMines)
    {
    int i,r=0,c=0;
    srand((unsigned)time(NULL));
    //create a random seed
    for(i=0;i<bombs;i++)
        {
        r = (rand() % rows)+1;
        while (r == rows)
            r = (rand() % rows)+1;
        c = (rand() % cols)+1;   
        while (c == cols)
            c = (rand() % cols)+1;
        boardWithMines[r][c] = MINE;
        //randomize the coordinates and place a mine
        }
    return boardWithMines;
    }
int
numberOfAdjMines(char **boardWithMines,int r,int c,int rows,int cols)
    {
    int count = 0;
    if(r>0 && c>0 && r<rows && c<cols)
        {
        if(boardWithMines[r][c] != MINE)
            {
            if(r-1>0 && c-1>0) 
                {
                if(boardWithMines[r-1][c-1] == MINE) //lower left
                    count++;
                }
            if(r-1>0)
                {
                if(boardWithMines[r-1][c] == MINE)  //lower middle
                    count++;
                }
            if(r-1>0 && c+1<cols)
                {
                if(boardWithMines[r-1][c+1] == MINE) //lower right
                    count++;
                }
            if(c-1>0)
                {
                if(boardWithMines[r][c-1] == MINE) //middle left
                    count++;
                }
            if(c+1<cols)
                {
                if(boardWithMines[r][c+1] == MINE) //middle right
                    count++;
                }
            if(r+1<rows && c-1>0)
                {
                if(boardWithMines[r+1][c-1] == MINE) //upper left
                    count++;
                }
            if((r+1)<rows)
                {
                if(boardWithMines[r+1][c] == MINE) //upper middle
                    count++;
                }
            if(r+1<rows && c+1<cols)
                {
                if(boardWithMines[r+1][c+1] == MINE) //upper right
                    count++;
                }
            }
            
        }
    return count;
    }

char **
fillBoard(char **boardWithMines,int rows,int cols)
    {
    int r,c;
    for(r=1;r<rows;r++)
        {
        for(c=1;c<cols;c++)
            {
            if(boardWithMines[r][c] != MINE) //fill the board
            boardWithMines[r][c] = '0' +  numberOfAdjMines(boardWithMines,r,c,rows,cols);
            }
        }
    return boardWithMines;
    }
char **
coverBoard(char **statusBoard,int rows,int cols)
    {
    int r,c;
    for(r=1;r<rows;r++)
        {
        for(c=1;c<cols;c++)
            {
            statusBoard[r][c] = COVERED; //cover the board
            }
        }
    return statusBoard;
    }
void 
displayBoard(char **m,int rows,int cols)
    {
    int r,c;
    for (r = 0; r < rows; ++r)
        {
        for (c = 0; c < cols; ++c)
            {
            printf("[%c] ",m[r][c]); //display the board
            }
        printf("\n");
        }
    printf("\n");
    return;
    }
int
uncover(char **sb,char **mb,int rows,int cols,int r,int c)
    {
    //uncover a slot
    if(r<=0 || r>=rows) return 0;
    else if(c<=0 || c>=cols) return 0;
    else if(sb[r][c] == UNCOVERED) return 0;
    else if(mb[r][c] == MINE) return 1;
    sb[r][c] = UNCOVERED;
    if(mb[r][c] > '0') return 0;
    uncover(mb,sb,rows,cols,r-1,c-1); //upper left
    uncover(mb,sb,rows,cols,r-1,c);   //above
    uncover(mb,sb,rows,cols,r-1,c+1); //upper right
    uncover(mb,sb,rows,cols,r,c-1);   //left middle
    uncover(mb,sb,rows,cols,r,c+1);   //right middle
    uncover(mb,sb,rows,cols,r+1,c-1); //lower left
    uncover(mb,sb,rows,cols,r+1,c);   //below
    uncover(mb,sb,rows,cols,r+1,c+1); //lower right
    return 0;
    }
int
endOfGame(char **sb,char **mb,int rows,int cols)
    {
    int r,c;
    //check if the game has ended
    for(r=1;r<rows;r++)
        {
        for(c=1;c<cols;c++)
            {
            if(sb[r][c] == COVERED)
                {
                if(mb[r][c] != MINE)
                    return 1;
                }
            }
        }
    return 0;
    }
int
move(char **sb,char **mb,int rows,int cols)
    {
    if(endOfGame(sb,mb,rows,cols) == 0)
        return 2; //if end of game
    else
        {
        int r,c;
        //if not end of game
        printf("Enter a row and a column:");
        scanf("%d %d",&r,&c);
        int mineORnot = uncover(sb,mb,rows,cols,r,c);
        //uncover
        if (mineORnot == 0)
            { //if not a mine continue
            displayCorrectedBoard(sb,mb,rows,cols);
            return 0;
            }
        else
            { //if it is a mine BOOM
            displayBoom();
            return 1;
            }
        }

    } 
