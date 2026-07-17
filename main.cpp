#include<iostream>
using namespace std;

int grid[9][9];
 
//Check if a number can be placed 
bool isSafe(int row, int col, int num)
{
  //Check row
 for(int i=0; i<9; i++)
   if(grid[row][i] == num)
     return false;

  //Check column
  for(int i=0; i<9; i++)
    if(grid[i][col] == num)
      return false;
  //Check 3*3 box
  int startRow = row - row % 3;
  int startCol = col - col % 3;

  for(int i =0; i<3; i++)
    for(int j=0; j<3; j++)
      if(grid[startRow + i][startCol + j] == num)
        return false;
  return true;
}

//Solve Sudoku using Backtracking
bool solveSudoku()
{
  for(int row=0; row<9; row++)
  {
    for(int col=0; col<9; col++)
      {
        if(grid[row][col] == 0)
          {
            for(int num =1; num<=9; num++)
              {
                if(isSafe(row, col, num))
                {
                  grid[row][col] = num;
                  if(solveSudoku())
                    return true;
                  grid[row][col] = 0;  //Backtarck
                }
              }    
              return false;
          }
      }
  }
return true;
}

//Print Sudoku
void printGrid()
{
  for (int i=0; i<9; i++)
  {
    for (int j=0; j<9; j++)
      cout << grid[i][j] << " ";
    cout << endl;
  }
}

int main()
{
  cout << "Enter Sudoku (use 0 for empty cells):\n";

  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
      cin>>grid[i][j];

  if (solveSudoku())
  {
    cout <<"\nSolved Sudoku:\n";
    printGrid();
  }
  else
  {
    cout << "NO solution exists";
  }
  return 0;
}

