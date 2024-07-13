
#include<stdio.h>
#define BOARD_SIZE 5
void displayChess(int chBoard[BOARD_SIZE][BOARD_SIZE]) {
   for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++)
         printf("%d ", chBoard[row][col]);
      printf("\n");
   }
}
int isQueenPlaceValid(int chBoard[BOARD_SIZE][BOARD_SIZE], int crntRow, int crntCol) {
   // checking if queen is in the left or not    
   for (int i = 0; i < crntCol; i++)    
      if (chBoard[crntRow][i])
         return 0;
   for (int i = crntRow, j = crntCol; i >= 0 && j >= 0; i--, j--)
      //checking if queen is in the left upper diagonal or not
      if (chBoard[i][j])       
         return 0;
   for (int i = crntRow, j = crntCol; j >= 0 && i < BOARD_SIZE; i++, j--)
      //checking if queen is in the left lower diagonal or not
      if (chBoard[i][j])      
         return 0;
   return 1;
}
int solveProblem(int chBoard[BOARD_SIZE][BOARD_SIZE], int crntCol) {
   //when N queens are placed successfully
   if (crntCol >= BOARD_SIZE)           
      return 1;
   // checking placement of queen is possible or not
   for (int i = 0; i < BOARD_SIZE; i++) {     
      if (isQueenPlaceValid(chBoard, i, crntCol)) {
         //if validate, place the queen at place (i, col)
         chBoard[i][crntCol] = 1;     
         //Go for the other columns recursively
         if (solveProblem(chBoard, crntCol + 1))    
            return 1;          
         //When no place is vacant remove that queen   
         chBoard[i][crntCol] = 0;        
      }
   }
   return 0;      
}
int displaySolution() {
   int chBoard[BOARD_SIZE][BOARD_SIZE];
   for(int i = 0; i < BOARD_SIZE; i++)
      for(int j = 0; j < BOARD_SIZE; j++)
         //set all elements to 0
         chBoard[i][j] = 0;      
   //starting from 0th column
   if (solveProblem(chBoard, 0) == 0) {     
      printf("Solution does not exist");
      return 0;
   }
   displayChess(chBoard);
   return 1;
}
int main() {
   displaySolution();
   return 0;
}
