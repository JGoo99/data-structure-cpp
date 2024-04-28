#include <iostream>
#include <cstdio>

using namespace std;

class Node {
  public:
    int a;
    Node *n;
};

class List {
public:
  List();
  void insert(int x);
  int nextForward();
  Node *head;
  Node *lastForward;
};

List::List() {
  head = NULL;
  lastForward = NULL;
}

void List::insert(int x) {
  Node *c;
  c = new Node;
  c->n = head;
  c->a = x;
  head = c;
}

int List::nextForward() {
  if (head == NULL)
    return -1;
  if (lastForward == NULL) {
    lastForward = head;
  } else {
    lastForward = lastForward->n;
  }
  if (lastForward == NULL) {
    return -1;
  } else {
    return lastForward->a;
  }
}
int n, m;
List map[1000];
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
  map[x].insert(y);
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
        while ((s = map[cur].nextForward()) != -1) {
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