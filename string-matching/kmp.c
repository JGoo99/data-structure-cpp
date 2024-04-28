#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *table, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int* getTable(char *pattern, int m) {
    int *table = (int *)malloc(sizeof(int) * m);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = table[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            table[i] = ++j;
        } else {
            table[i] = 0;
        }
    }
    return table;
}

void kmp(char *text, int n, char *pattern, int m, int *table) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            if (j == m) {
                printf("%d번째 인덱스에서 찾았습니다.", i);
            } else {
                j++;
            }
        }
    }
}

int main() {
    char text[] = "abaaacabcabadadaabcabada";
    int n = strlen(text);
    char pattern[] = "abcabada";
    int m = strlen(pattern);
    int *table = getTable(pattern, m);

    print(table, m);

    kmp(text, n, pattern, m, table);
    free(table);
    return 0;
}
