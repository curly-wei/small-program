#include <stdio.h>
#include <stdlib.h>

void iter_2d(const size_t row, 
             const size_t column,
             //int [row][column],
             int** arr) {
  for (size_t r = 0; r < row; ++r)
    for (size_t c = 0; c < column; ++c)
      printf("[%zu][%zu] = %d\n",r,c,arr[r][c]);
    
}

int main(int argc, char const *argv[]) {
  const size_t column = 3, row = 4;

  //low speed
  int** arr = (int**)malloc(sizeof(int*) * row);
  for (size_t i = 0; i < row; i++)
    arr[i] = (int*)malloc(sizeof(int) * column);
  
  //high speed clang or gcc only
  //int (*arr)[column] = malloc( sizeof(int[row][column]) );

  int count = 0;
  for (size_t i = 0; i < row; i++)
    for (size_t j = 0; j < column; j++)
      arr[i][j] = ++count;

  iter_2d(column,row,arr);

  for (size_t i = 0; i < row; i++)
    free(arr[i]);
  free(arr);
  

  return 0;
}
