#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_SIZE 100

int A[MAX_SIZE];
int S;

int indexOf(int x) {
  for (int i = 0; i < S; i++) {
    if (A[i] == x) {
      return i;
    }
  }
  return -1;
}

void insert(int x) {
  if (S < MAX_SIZE) {
    A[S] = x;
    S++;
  } else {
    printf("Array is full.\n");
  }
}

void del(int index) {
  A[index] = A[S - 1];
  S--;
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
        printf("%d Found At Index %d\n", x, index);
      }
    }
    else if (c == 'i') {
      printf("<<<<<< Insert >>>>>>\n");
      printf("Enter value to insert: ");

      cin >> x;
      if (indexOf(x) == -1) {
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
