//solve the puzzle
for(int i = 0; i < sizeof(board) / sizeof(board[0]); i++)
{
  for (int j = 0; j < sizeof(board[i]) / sizeof(board[i][0]); j++)
  {
    if (board[i][j] == -1) {
      int shouldGo = -1;//the number that should go in that spot

      for (int n = 1; n < 10; n++) {
        int row = i;
        int col = j;
        int found = 0;

        //check up and down
        while ((row+1)%9 != i) {
          if (n == board[row][col]) {
            found = 1;
          }
        }

        if (found == 1) {
          continue;
        }

        //check side to side
        while ((col+1)%9 != j) {
          if (n == board[row][col]) {
            found = 1;
          }
        }

        if (found == 1) {
          continue;
        }

        //check in square
        while ((i / 3)+((row=row+1)%3) != i) {
          while ((j / 3)+((col=col+1)%3) != j) {
            if (n == board[row + (i / 3)][col + (j / 3)]) {
              found = 1;
            }
          }
        }

        if (found == 1) {
          continue;
        }

        //if we haven't continued, this one is an option
        if (shouldGo == -1) {
          shouldGo = n;
        } else {
          shouldGo = -2;
        }
      }

      if (shouldGo >= 0) { board[i][j] = shouldGo; }
      }
    }
  }
