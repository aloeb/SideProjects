#include <stdio.h>

int main() {
  int board[9][9] = {
{0,0,19,18,12,0,0,0,14},
{0,11,0,0,0,0,0,0,0},
{0,0,0,19,0,0,17,13,0},
{16,0,0,0,0,17,0,0,0},
{0,0,0,12,11,0,0,19,16},
{19,12,18,0,14,0,0,0,11},
{0,0,0,0,0,0,0,11,13},
{15,18,0,0,0,0,0,12,0},
{0,0,0,0,16,0,0,15,0}
  };

  //solve the puzzle
  for(int i = 0; i < sizeof(board) / sizeof(board[0]); i++)
  {
    for (int j = 0; j < sizeof(board[i]) / sizeof(board[i][0]); j++)
    {
      if (board[i][j] < 10) {
        int shouldGo = 0;//the number that should go in that spot

        for (int n = board[i][j]+1; n < 10; n++) {
          int row = i;
          int col = j;
          int found = 0;

          //check up and down
          while ((row=((row+1)%9)) != i) {
            //printf("Stuck1");
            int val = board[row][col];
            if (val > 10) {
              val-=10;
            }
            if (n == val) {
              found = 1;
            }
          }

          if (found == 1) {
            continue;
          }

          //check side to side
          while ((col=((col+1)%9)) != j) {
            //printf("Stuck2");
            int val = board[row][col];
            if (val > 10) {
              val-=10;
            }
            if (n == val) {
              found = 1;
            }
          }

          if (found == 1) {
            continue;
          }

          //check in square
          while (((i / 3)*3)+(row=((row+1)%3)) != i) {
            while (((j / 3)*3)+(col=((col+1)%3)) != j) {
              //printf("Stuck3");
              //printf("row: %d, col: %d", (i / 3)+(((row)%3)), (j / 3)+(((col)%3)));
              int val = board[row + (i / 3)*3][col + (j / 3)*3];
              if (val > 10) {
                val-=10;
              }
              if (n == val) {
                found = 1;
              }
            }
          }

          if (found == 1) {
            continue;
          }

          //if we haven't continued, then this is an option
          shouldGo = n;
          break;
        }

        board[i][j] = shouldGo;
        if (!(shouldGo > 0)) {
          //otherwise we messed up earlier, so lets backtrack
          do {
            j-=1;
          } while(board[i][j] > 10);
          j-=1;
          while (j < 0) {
            j += sizeof(board[i]) / sizeof(board[i][0]);
            i -= 1;
          }
        }
      }
    }
  }

  //print the board and make it look all pretty :)
  for(int i = 0; i < sizeof(board) / sizeof(board[0]); i++)
  {
    if (i % 3 == 0) {
      printf("|-----------------|");
      printf("\n");
    }
    for (int j = 0; j < sizeof(board[i]) / sizeof(board[i][0]); j++)
    {
      int value = board[i][j];
      if (value > 10) {
        value-=10;
      }
      if (j % 3 == 0)
        printf("|");
      if (j % 3 == 2) {
        if (value == 0)
          printf(" ");
        else
          printf("%d", value);
      } else {
        if (value == 0)
          printf("  ");
        else
          printf("%d ", value);
      }
    }
    printf("|\n");
  }
  printf("|-----------------|"); //last line that doesn't get taken care of by the loop
  printf("\n");

  return 0;
}
