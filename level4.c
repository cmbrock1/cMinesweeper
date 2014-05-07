#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "io.h"
#define MINE '*' 
#define COVERED '#' 
#define UNCOVERED '_' 
int 
main(int argc,char **argv)
    {
    system("clear");
    char **mineBoard = 0;
    char **statusBoard = 0;
    int rows = atoi(argv[1])+1;
    int cols = atoi(argv[2])+1;
    int mines = atoi(argv[3]);
    mineBoard = makeEmptyBoard(mineBoard,rows,cols);
    mineBoard = placeMines(rows,cols,mines,mineBoard);
    mineBoard = fillBoard(mineBoard,rows,cols);
    statusBoard = makeEmptyBoard(statusBoard,rows,cols);
    statusBoard = coverBoard(statusBoard,rows,cols);
    displayCorrectedBoard(statusBoard,mineBoard,rows,cols);
    int move = endOfGame(statusBoard,mineBoard,rows,cols);
    printf("move = %d\n",move);
    int mineORnot = uncover(mineBoard,statusBoard,rows,cols,4,4);
    printf("mineORnot = %d\n",mineORnot);
    displayCorrectedBoard(statusBoard,mineBoard,rows,cols);
    move = endOfGame(statusBoard,mineBoard,rows,cols);
    printf("move = %d\n",move);

    //statusBoard[2][4] = UNCOVERED;
    //statusBoard[3][3] = UNCOVERED;
    //statusBoard[4][2] = UNCOVERED;
    //displayCorrectedBoard(statusBoard,mineBoard,rows,cols);
    //int r,c;
    //for(r=0;r<rows;r++)
    //    {
    //    for(c=0;c<cols;c++)
    //        statusBoard[r][c] = UNCOVERED;
    //    }
    //displayCorrectedBoard(statusBoard,mineBoard,rows,cols);
    //displayBoom();
    return 0;
    }
