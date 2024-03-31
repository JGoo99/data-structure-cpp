#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_SIZE 100

int A[MAX_SIZE];
int B[MAX_SIZE];
int S;

int indexOf(int x) {
  int start = 0;
  int end = S - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (A[mid] == x) {
      return mid;
    }
    else if (A[mid] < x) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }
  return -1;
}

int findInsertPosition(int x) {
  int start = 0;
  int end = S - 1;
  int insertPosition = S;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (A[mid] <= x) {
      start = mid + 1;
    }
    else {
      insertPosition = mid;
      end = mid - 1;
    }
  }
  if (insertPosition > 0 && B[insertPosition - 1] == 0) {
    return insertPosition - 1;
  }
  return insertPosition;
}

int findNextEmptyPosition(int insertPosition) {
  int i = insertPosition;
  for (; i < S; i++) {
    if (B[i] == 0) {
      return i;
    }
  }
  return i;
}

void insert(int x) {
  if (S == MAX_SIZE) {
    printf("Array is full.\n");
    return;
  }

  int insertPosition = indexOf(x);

  if (insertPosition != -1 && B[insertPosition] == 0) {
    B[insertPosition] = 1;
  } else {
    insertPosition = findInsertPosition(x);
    int rightEmptyPosition = findNextEmptyPosition(insertPosition);
    for (int i = rightEmptyPosition; i > insertPosition; i--) {
      A[i] = A[i - 1];
      B[i] = B[i - 1];
    }
    B[insertPosition] = 1;
    if (rightEmptyPosition == S) {
      S++;
    }
  }
  A[insertPosition] = x;
}

void del(int index) {
  B[index] = 0;
}

void printArray() {
  // 인덱스
  for (int j = 0; j < S; j++) {
    printf("%3d   ", j);
  }
  printf("\n");
  // 요소
  for (int j = 0; j < S; j++) {
    printf("%3d   ", A[j]);
  }
  printf("\n");
  // 마커 (0:none, 1:fill)
  for (int j = 0; j < S; j++) {
    printf("%3d   ", B[j]);
  }
  printf("\n");
}

int main() {
  char c;
  int x;

  while (true) {
    printf("Size: %d\n", S);
    printArray();

    cin >> c;
    if (c == 'f') {
      printf("<<<<<< Find >>>>>>\n");
      printf("Enter value to find: ");

      cin >> x;
      int index = indexOf(x);
      if (index == -1) {
        printf("%d Not Found\n", x);
      } else {
        if (B[index] == 0) {
          printf("%d Not Found\n", x);
        } else {
          printf("%d Found At Index %d\n", x, index);
        }
      }
    }
    else if (c == 'i') {
      printf("<<<<<< Insert >>>>>>\n");
      printf("Enter value to insert: ");

      cin >> x;
      int index = indexOf(x);
      if (index == -1 || B[index] == 0) {
        insert(x);
      }
    }
    else if (c == 'd') {
      printf("<<<<<< Delete >>>>>>\n");
      printf("Enter value to delete: ");

      cin >> x;
      int index = indexOf(x);
      if (index == -1) {
        printf("%d Not Found\n", x);
      } else {
        del(index);
      }
    }
    else if (c == 'q') {
      printf("<<<<<< Quit >>>>>>\n");
      break;
    }
    else {
      printf("Retry [f:find, i:insert, d:delete, q:quit]\n");
    }
  }
  return 0;
}
