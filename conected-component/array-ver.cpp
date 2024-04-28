#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int map[1000][1000];
int visited[1000];
int lastForward[1000];
int stack[1000];
int top = 0;
int lastStart = 0;

void push(int x) {
  stack[top++] = x;
}

int pop() {
  return stack[--top];
}

bool isEmpty() {
  return top == 0;
}

void setLink(int x, int y) {
  map[x][y] = 1;
}

bool isMarked(int x) {
  return visited[x] == 1;
}

void mark(int x) {
  visited[x] = 1;
}

int nextStart() {
  lastStart++;
  while (lastStart <= n) {
    if (!isMarked(lastStart)) {
      return lastStart;
    }
    lastStart++;
  }
  return -1;
}

int nextForward(int x) {
  lastForward[x]++;
  while (lastForward[x] <= n) {
    if (map[x][lastForward[x]] == 1) {
      return lastForward[x];
    }
    else {
      lastForward[x]++;
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    setLink(x, y);
    setLink(y, x);
  }

  printf("===========result===========\n");

  int cur = 0;
  while ((cur = nextStart()) != -1) {
    push(cur);
    while (!isEmpty()) {
      cur = pop();
      if (!isMarked(cur)) {
        printf("%d ", cur);
        mark(cur);
        int s;
        while ((s = nextForward(cur)) != -1) {
          if (!isMarked(s)) {
            push(s);
          }
        }
      }
    }
    printf("\n");
  }
  return 0;
}