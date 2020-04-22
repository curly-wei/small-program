#include <stdio.h>

void swap_val(int* restrict a, int* restrict b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void bubble_sort(int* arr, const size_t length) {
  if (length < 2||arr == NULL) return;
  size_t vertex = length -1;
  for (size_t i = 0; i < vertex; i++) {
    for (size_t j = 0; j < vertex-i; j++) {
      if (arr[j] > arr [j+1]) 
        swap_val(&arr[j+1], &arr[j]);
    }
  }
}

void cocktail_sort(int* arr, const size_t length) {
  if (length<2 || arr==NULL) return;
  size_t left = 0;
  size_t right = length - 1;
  while (left < right) {
    for (size_t i = left; i < right; i++) {
      if (arr[i] > arr[i+1])
        swap_val(&arr[i], &arr[i+1]);
    } 
    --right;
    for (size_t i = right; i < left; i--) { 
      if (arr[i-1] > arr[i])
        swap_val(&arr[i-1], &arr[i]);
    }
  }
}

int main(int argc, char const *argv[]) {
  int array[] = { 5, 7, 6, 4, 3 } ;
  size_t arr_size = (sizeof(array)/sizeof(array[0]));
  cocktail_sort(array, arr_size);
  for (size_t i = 0; i < arr_size; i++)
    printf("%d\n",array[i]);
  return 0;
}
