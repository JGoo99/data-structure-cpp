#include <stdio.h>
#include <stdlib.h>

void print(int output[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int* naiveMatch(char T[], int n, char P[], int m) {
  int* output = (int*)malloc(n * sizeof(int));

  for (int i = 0; i < n - m; i++) {
    for (int j = 0; j < m ; j++) {
      if (T[i + j] == P[j]) {
        output[i + j] = max(output[i + j], j + 1);
      } else {
        break;
      }
    }
    print(output, n);
  }
  return output;
}

int main() {
  char T[] = "abababacab";
  char P[] = "ababaca";
  int n = sizeof(T) / sizeof(T[0]);
  int m = sizeof(P) / sizeof(P[0]);

  int* result = naiveMatch(T, n, P, m);

  free(result);
  return 0;
}