#include <stdio.h>
#include <stdlib.h>
#include "FinalProject.h"

/*
Main function for the tictactoe program
*/

int main() {
  char winner='\0';
  char Player='X';
  char hor;
  char ver;
  char** grid = makegrid();

  while(!winner && !lines(grid)) {
    print(grid);

    /*
    Displays the turn of the player on every play
    */

    printf("Player %c, it is now your turn: ", Player);
    scanf(" %c %c", &hor, &ver);

    /*
  Allows for the movemnt of spots and displays an Error message if one where to chose a spot thats taken
    */

    int horizontal = hor - 'A';
    int vertical = ver - '1';
    if (grid[horizontal][vertical] == ' ')
    {
      grid[horizontal][vertical] = Player;
      if (Player == 'X') {
	Player = 'O';
      }
       else {
	Player = 'X';
      }
      winner = finalplay(grid, horizontal, vertical);
    }
    else {
      printf("Spot is taken... choose another.\n");
    }
  }

  /*
Game Endinds for Player X or O Winning or Tie Game
  */

  print(grid);
  if (winner == 'X' || winner == 'O')

  {
    printf("%c Wins!\n", winner);
  }
  else {
    printf("Tie Game!\n");
  }

  return 0;
}
