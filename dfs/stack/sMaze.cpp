#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_SIZE 100

int maze[MAX_SIZE][MAX_SIZE];
int stack[MAX_SIZE * MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];

int m, n;
int top;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

void validateSize(int& m, int& n) {
  while (m > MAX_SIZE || n > MAX_SIZE) {
    printf("미로의 최대 사이즈(100 * 100) 를 초과했습니다. 다시 입력해주세요: ");
    cin >> m >> n;
  }
}

void initMaze() {
  printf("미로의 행(세로)과 열(가로)을 입력해주세요: ");
  cin >> m >> n;

  validateSize(m, n);

  for (int i = 0; i < m; i++) {
    printf("%d번 줄 (%d/%d) [0: 길, 1: 벽]: ", i + 1, i + 1, m);
    for (int j = 0; j < n; j++) {
      cin >> maze[i][j];
    }
  }
  maze[0][0] = 0; // 시작 지점
  maze[m - 1][n - 1] = 2; // 도착 지점
}

void initStack() {
  top = -1;
}

bool isEmpty() {
  return top == -1;
}

void push(int x) {
  stack[++top] = x;
}

int pop() {
  return stack[top--];
}

void printMaze() {
  printf("<<<<< 미로 >>>>>\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

void printVisit() {
  printf("<<< 지나간 길 >>>\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", visit[i][j]);
    }
    printf("\n");
  }
}


bool dfs() {
  initStack();

  push(0);
  push(0);

  while (!isEmpty()) {
    int curJ = pop();
    int curI = pop();

    if (visit[curI][curJ]) {
      continue;
    }

    if (maze[curI][curJ] == 2) {
      visit[curI][curJ] = true;
      return true;
    }

    visit[curI][curJ] = true;

    for (int l = 0; l < 4; l++) {
      int nextI = curI + di[l];
      int nextJ = curJ + dj[l];

      if (nextI < 0 || nextI > m - 1 || nextJ < 0 || nextJ > n - 1) continue;

      if (maze[nextI][nextJ] != 1 && !visit[nextI][nextJ]) {
        push(nextI);
        push(nextJ);
      }
    }
  }
  return false;
}


int main() {
  initMaze();

  if (dfs()) {
    cout << "출구를 찾았습니다!" << endl;
  } else {
    cout << "출구를 찾을 수 없습니다." << endl;
  }

  printMaze();
  printVisit();
}