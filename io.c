#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#define MINE '*'
#define COVERED '#'
#define UNCOVERED '_'
void
displayCorrectedBoard(char **sb,char **mb,int rows,int cols)
    {
    int r,c;
    system("clear");
    displayTitle();
    //display the title
    if(rows < 11 && cols < 11)
        { 
        for(r=0;r<rows;r++)
            {
            for(c=0;c<cols;c++)
                {
                if(r == 0 || c == 0)
                    printf("-%c- ",mb[r][c]);
                else if (sb[r][c] != UNCOVERED)
                    printf("[%c] ",sb[r][c]);
                else 
                    printf("[%c] ",mb[r][c]);
                } //display corrected board with less that 10 rows or columns
            printf("\n");
            printf("\n");
            }
        printf("\n");
        }
    else
        {
        for(r=0;r<rows;r++)
            {
            for(c=0;c<cols;c++)
                {
                if(c == 0)
                    printf("-%2d- ",r);
                else if(r == 0)
                    printf("-%2d- ",c);
                else if(mb[r][c] == MINE && sb[r][c] == UNCOVERED)
                    printf("[**] ");
                else if(sb[r][c] == UNCOVERED)
                    printf("[ %c] ",mb[r][c]);
                else
                    printf("[ %c] ",sb[r][c]);
                } //display corrected board with more than 10 rows or columns
            printf("\n");
            printf("\n");
            }
        printf("\n");
        }
    return;
    }            
void
displayBoom()
    {
    system("clear");
    printf("               ,----..       ,----..             ____   \n");
    printf("    ,---,.    /   /   \\     /   /   \\          ,'  , `. \n"); 
    printf("  ,'  .'  \\  /   .     :   /   .     :      ,-+-,.' _ | \n"); 
    printf(",---.' .' | .   /   ;.  \\ .   /   ;.  \\  ,-+-. ;   , || \n"); 
    printf("|   |  |: |.   ;   /  ` ;.   ;   /  ` ; ,--.'|'   |  ;| \n"); 
    printf(":   :  :  /;   |  ; \\ ; |;   |  ; \\ ; ||   |  ,', |  ': \n"); 
    printf(":   |    ; |   :  | ; | '|   :  | ; | '|   | /  | |  || \n"); 
    printf("|   :     \\.   |  ' ' ' :.   |  ' ' ' :'   | :  | :  |, \n"); 
    printf("|   |   . |'   ;  \\; /  |'   ;  \\; /  |;   . |  ; |--'  \n"); 
    printf("'   :  '; | \\   \\  ',  /  \\   \\  ',  / |   : |  | ,     \n"); 
    printf("|   |  | ;   ;   :    /    ;   :    /  |   : '  |/      \n"); 
    printf("|   :   /     \\   \\ .'      \\   \\ .'   ;   | |`-'       \n"); 
    printf("|   | ,'       `---`         `---`     |   ;/           \n"); 
    printf("`----'                                 '---'            \n"); 
    printf("       _.-._        \n");
    printf("      ({  ` )       \n");
    printf("       ` |''   *WHAM! YOU HIT A MINE*\n");
    printf("        \\_/   *GAME OVER! YOU LOSE!*\n");
    printf(" .(      |      ), \n");
    printf("`  -----' `-----  ' \n"); //BOOM
    return;
    }
void
displayTitle()
    {
    printf("   _____   ___ _______  ___________ ___________      _______________________________________________________ \n");
    printf("  /     \\ |   |\\      \\ \\_   _____//   _____/  \\    /  \\_   _____/\\_   _____/\\______   \\_   _____/\\______   \\\n");
    printf(" /  \\ /  \\|   |/   |   \\ |    __)_ \\_____  \\\\   \\/\\/   /|    __)_  |    __)_  |     ___/|    __)_  |       _/\n");
    printf("/    Y    \\   /    |    \\|        \\/        \\\\        / |        \\ |        \\ |    |    |        \\ |    |   \\\n");
    printf("\\____|__  /___\\____|__  /_______  /_______  / \\__/\\  / /_______  //_______  / |____|   /_______  / |____|_  /\n");
    printf("        \\/            \\/        \\/        \\/       \\/          \\/         \\/                   \\/         \\/ \n");
    printf("\n");
    return;
    }
void
displayNoBoom()
    {
    system("clear");
    printf("\n");
    printf(" _        _          _      _                       _             _            _             _        _        _\n");     
    printf("/\\ \\     /\\_\\       /\\ \\   /\\_\\                    / /\\      _   /\\ \\         /\\ \\     _    /\\_\\     /\\_\\     /\\_\\  \n"); 
    printf("\\ \\ \\   / / /      /  \\ \\ / / /         _         / / /    / /\\ /  \\ \\       /  \\ \\   /\\_\\ / / /    / / /    / / /  \n"); 
    printf(" \\ \\ \\_/ / /      / /\\ \\ \\\\ \\ \\__      /\\_\\      / / /    / / // /\\ \\ \\     / /\\ \\ \\_/ / // / /_   / / /_   / / /_  \n"); 
    printf("  \\ \\___/ /      / / /\\ \\ \\\\ \\___\\    / / /     / / /_   / / // / /\\ \\ \\   / / /\\ \\___/ // /___/\\ / /___/\\ / /___/\\ \n"); 
    printf("   \\ \\ \\_/      / / /  \\ \\_\\\\__  /   / / /     / /_//_/\\/ / // / /  \\ \\_\\ / / /  \\/____/ \\____ \\ \\\\____ \\ \\\\____ \\ \\\n"); 
    printf("    \\ \\ \\      / / /   / / // / /   / / /     / _______/\\/ // / /   / / // / /    / / /      / / /    / / /    / / /\n"); 
    printf("     \\ \\ \\    / / /   / / // / /   / / /     / /  \\____\\  // / /   / / // / /    / / /      / / /    / / /    / / / \n"); 
    printf("      \\ \\ \\  / / /___/ / // / /___/ / /     /_/ /\\ \\ /\\ \\// / /___/ / // / /    / / /      _\\/_/    _\\/_/    _\\/_/  \n"); 
    printf("       \\ \\_\\/ / /____\\/ // / /____\\/ /      \\_\\//_/ /_/ // / /____\\/ // / /    / / /      /\\_\\     /\\_\\     /\\_\\    \n"); 
    printf("        \\/_/\\/_________/ \\/_________/           \\_\\/\\_\\/ \\/_________/ \\/_/     \\/_/       \\/_/     \\/_/     \\/_/    \n"); 
                                                                                                                       
    printf("WELL THIS IS AWKWARD............\n");
    printf("I REALLY DIDN'T EXPECT YOU TO MAKE IT THROUGH MY MINEFIELD!\n");
    printf("HMM GUESS YOU WIN THIS ROUND, BUT...\n");
    printf("*puts on best Arnold Schwarzenegger impression*\n");
    printf("\"I'LL BE BACK\"\n");
    return;
    }
