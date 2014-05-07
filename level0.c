#include <stdio.h>
#include <stdlib.h>
#include "game.h"
int
main(int argc,char **argv)
    {
    int i;
    char **mineBoard = 0;
    char **statusBoard = 0;
    //for(i=0;i<argc;i++)
        //printf("argv[%d] = %s\n",i,argv[i]);
    int rows = atoi(argv[1]) + 1;
    //printf("rows = %d\n",rows);
    int colums = atoi(argv[2]) + 1;
    //printf("cols = %d\n",colums);
    int mines = atoi(argv[3]);
    //printf("mines = %d\n",mines);
    mineBoard = makeEmptyBoard(mineBoard,rows,colums);
    //printf("\n");
    statusBoard = makeEmptyBoard(statusBoard,rows,colums);
    //printf("\n");
    //printf("rows = %d\n",rows);
    //printf("cols = %d\n",colums);
    
    //displayBoard(mineBoard,rows,colums);
    //displayBoard(statusBoard,rows,colums);
    coverBoard(statusBoard,rows,colums);
    displayBoard(statusBoard,rows,colums);
    mineBoard = placeMines(rows,colums,mines,mineBoard);
    mineBoard = fillBoard(mineBoard,rows,colums);
    displayBoard(mineBoard,rows,colums);

    /*int r,c;
    for (r=0;r<rows;r++)
        {
        for (c=0;c<colums;c++)
            {
            printf("[%c] ",mineBoard[r][c]);
            }
        printf("\n");
        }*/
    //free(mineBoard);
    //free(statusBoard);
    return 0;
    }
