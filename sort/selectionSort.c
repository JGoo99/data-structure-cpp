#include <stdio.h>

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}

void sort(int a[], int n) {
  int i, j, m;

  for (i = 0; i < n; i++) {
    m = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[m]) {
        m = j;
      }
    }
    swap(a, i, m);
    print(a, n);
  } 
  return;
}

int main() {
  int a[] = {1, 3, 9, 2, 8, 6, 7, 4, 10, 5};
  int n = sizeof(a) / sizeof(int);

  sort(a, n);
  return 0;
}