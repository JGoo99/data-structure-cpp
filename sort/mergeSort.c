#include <stdio.h>

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n\n");
}

void merge(int a[], int tmp[], int start, int mid, int end) {
  for (int i = start; i <= end; i++) {
    tmp[i] = a[i];
  }

  int p1 = start;
  int p2 = mid + 1;
  printf("p1=%d", p1);
  printf("  p2=%d", p2);
  printf(" start=%d", start);
  printf(" mid=%d", mid);
  printf(" end=%d\n", end);
  printf("before = ");
  print(a, 10);
  int idx = start;
  while (p1 <= mid && p2 <= end) {
    if (tmp[p1] <= tmp[p2]) {
      a[idx] = tmp[p1];
      p1++;
    } else {
      a[idx] = tmp[p2];
      p2++;
    }
    idx++;
  }

  // 앞쪽 배열의 값이 남은 경우
  for (int i = 0; i <= mid - p1; i++) {
    a[idx + i] = tmp[p1 + i];
  }
  printf("after = ");
  print(a, 10);
}

void mergeSort(int a[], int tmp[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergeSort(a, tmp, start, mid);
    mergeSort(a, tmp, mid + 1, end);
    merge(a, tmp, start, mid, end);
  }
}

void frontMergeSort(int a[], int n) {
  int tmp[n];
  mergeSort(a, tmp, 0, n - 1);
}

int main() {
  int a[] = {3, 9, 4, 7, 5, 1, 0, 6, 8, 2};
  int len = sizeof(a) / sizeof(int);

  print(a, 10);
  frontMergeSort(a, len);
  print(a, 10);

  return 0;
}