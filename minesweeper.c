/******************************************************************************* 
 *  cMinesweeper is my interpretation of the classic minesweeper game only     *
 *  text based and written in ASCII C                                          *
 *                                                                             *
 *  Copyright (C) <2014>  Cameron M. Brock                                     *
 *                                                                             *
 *  This program is free software: you can redistribute it and/or modify       *
 *  it under the terms of the GNU General Public License as published by       *
 *  the Free Software Foundation, either version 3 of the License, or          *
 *  (at your option) any later version.                                        *
 *                                                                             *
 *  This program is distributed in the hope that it will be useful,            *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 *  GNU General Public License for more details.                               *
 *                                                                             *
 *  You should have received a copy of the GNU General Public License          *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.      *
 *                                                                             *
 *******************************************************************************/
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
    //add a row for coordinates
    int cols = atoi(argv[2])+1;
    //add a column for coordinates
    int mines = atoi(argv[3]);
    //get number of mines
    if(mines == 0 || mines >= (rows-1) * (cols-1) || rows == 0 || cols == 0)
        {
        //check for valid input values
        printf("Please input valid values for the number of rows columns and mines\n");
        exit(1);
        }
    mineBoard = makeEmptyBoard(mineBoard,rows,cols);
    //initialize mineBoard
    mineBoard = placeMines(rows,cols,mines,mineBoard);
    //place the mines
    mineBoard = fillBoard(mineBoard,rows,cols);
    //fill remaining slots with the number of adj mines
    statusBoard = makeEmptyBoard(statusBoard,rows,cols);
    //make an empty statusBoard
    statusBoard = coverBoard(statusBoard,rows,cols);
    //cover all the slots on the statusBoard
    gameloop(statusBoard,mineBoard,rows,cols);
    //begin the game
    return 0;
    }
void
gameloop(char **sb,char **mb,int rows,int cols)
    {
    system("clear");
    displayTitle();
    //display the title
    displayCorrectedBoard(sb,mb,rows,cols);
    //display the board
    int moveReturn = move(sb,mb,rows,cols);
    //make a move
    while(moveReturn == 0)
        {
        //continue playing
        moveReturn = move(sb,mb,rows,cols);
        }
    if(moveReturn == 1)
        displayBoom();
        //if you lose then boom
    if(moveReturn == 2)
        displayNoBoom();
        //if you win no boom
    return;
    }
