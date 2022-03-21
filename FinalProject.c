/*
Final Project: This is a two player Tictactoe game that just uses the terminal to plau
*/
#include "FinalProject.h"



/*
Creates the grid with all of the spacing.
*/

char** makegrid() {
  char** BASIC = calloc(3, sizeof(char*));
  for(int a = 0; a < 3; ++a) {
    BASIC[a] = calloc(3, sizeof(char));
  }

  for(int b=0; b < 3; ++b) {
    for(int c=0; c < 3; ++c) {
      BASIC[b][c] = ' ';
    }
  }

  return BASIC;
}

/*
Prints out the actual grid in the terminal
*/

void print(char** grid) {
  printf("  1 2 3\n");
  for(int a = 0; a < 3; ++a) {
    printf("%c|", 'A' + a);
    for(int b = 0; b < 3; ++b) {
      printf("%c|", grid[a][b]);
    }
    printf("\n");
  }
}

/*
Functions that returns true if the game ends in a Tie
*/

int lines(char** grid) {
  for(int b = 0; b < 3; ++b) {
    for(int a = 0; a < 3; ++a) {
      if (grid[a][b] == ' ') {
        /*
        This shows that tells the game that there are still empty spots so the game will continue running
        */
        return 0;
      }
    }
  }
  /*
  This return belows means that game has ended in a Tie because there are no more empty spots
  */
  return 1;
}

/*
This will return either "X" or "O" if either of them prefrom the final move/play
*/
char finalplay(char** grid, int a, int b) {
  if (grid[a][b] == grid[a][(1+b)%3]
   && grid[a][b] == grid[a][(2+b)%3])
  {
    /*
    Final play was won by in a vertical manner = X
                                                 X
                                                 X
    */
    return grid[a][b];
  }
  else if (grid[a][b] == grid[(1+a)%3][b]
          && grid[a][b] == grid[(2+a)%3][b])
  {
    /*
    Final play was won in a horizontal manner = XXX
    */
    return grid[a][b];
  }
  else if (a==b && grid[a][b] == grid[(1+a)%3][(b+1)%3]
                  && grid[a][b] == grid[(2+a)%3][(b+2)%3])
  {

    /*
                                                   X
                                                  X
    Final play was won by in a diagonal manner = X
    */
    return grid[a][b];
  }
  else if (a+b == 2 && grid[a][b] == grid[(2+a)%3][(b+1)%3]
                    && grid[a][b] == grid[(1+a)%3][(b+2)%3])
  {

    /*
    Final play was won by in a diagonal manner = X
                                                  X
                                                   X
    */

    return grid[a][b];
  }
  else {

    return 0;
  }
}
