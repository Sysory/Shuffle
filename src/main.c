#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 19

void init(int *, int);
void shuffle(int *, int);
void output(int *, int);
void swap(int *, int, int);

int main(void) {
  srand(time(NULL));

  int arr[N];
  init(arr,N);

  shuffle(arr, N);

  output(arr, N);
  return 0;
}

void output(int *arr, int n) {
  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void shuffle(int *arr, int n) {
  for (int i=0; i<n/2; i++) {

    int offset = n-1-i;
    for (int j=0; j<=i; j++) {
      if (rand()%2) {
        swap(arr, j, j+offset);
      }
    }
  }
}

void swap(int *arr, int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void init(int *arr, int n) {
  for (int *p = arr; p-arr < n; p++) {
    *p = p-arr;
  }
}
