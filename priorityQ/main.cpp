#include <iostream>
#include <cstdio>

using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

class PQMin {
public:
  PQMin();
  int size();
  int top();
  void insert(int x);
  void del();
  int a[1000];
  int n;
};

PQMin::PQMin() {
  n = 0;
}

int PQMin::size() {
  return n;
}

int PQMin::top() {
  if (n <= 0) {
    return -1;
  }
  return a[1];
}

void PQMin::insert(int x) {
  int i;
  n++;
  a[n] = x;
  i = n;
  while (i != 1) {
    if (a[i / 2] <= a[i]) {
      break;
    }
    swap(a[i / 2], a[i]);
    i = i / 2;
  }
}

void PQMin::del() {
  if (n == 0) return;

  int i, j;
  a[1] = a[n];
  n--;
  i = 1;
  while (true) {
    if (i * 2 > n) break;
    if (i * 2 == n) {
      if (a[i] <= a[i * 2]) {
        break;
      } else {
        swap(a[i], a[i * 2]);
        i = i * 2;
      }
    } else {
      if (a[i * 2] < a[i * 2 + 1]) {
        j = i * 2;
      } else {
        j = i * 2 + 1;
      }
      if (a[i] <= a[j]) {
        break;
      } else {
        swap(a[i], a[j]);
        i = j;
      }
    }
  }
}

class PQMax {
public:
  PQMax();
  int size();
  int top();
  void insert(int x);
  void del();
  int a[1000];
  int n;
};

PQMax::PQMax() {
  n = 0;
}

int PQMax::size() {
  return n;
}

int PQMax::top() {
  if (n <= 0) {
    return -1;
  }
  return a[1];
}

void PQMax::insert(int x) {
  int i;
  n++;
  a[n] = x;
  i = n;
  while (i != 1) {
    if (a[i / 2] >= a[i]) {
      break;
    }
    swap(a[i / 2], a[i]);
    i = i / 2;
  }
}

void PQMax::del() {
  if (n == 0) return;

  int i, j;
  a[1] = a[n];
  n--;
  i = 1;
  while (true) {
    if (i * 2 > n) break;
    if (i * 2 == n) {
      if (a[i] >= a[i * 2]) {
        break;
      } else {
        swap(a[i], a[i * 2]);
        i = i * 2;
      }
    } else {
      if (a[i * 2] > a[i * 2 + 1]) {
        j = i * 2;
      } else {
        j = i * 2 + 1;
      }
      if (a[i] >= a[j]) {
        break;
      } else {
        swap(a[i], a[j]);
        i = j;
      }
    }
  }
}

int main() {
  char c;
  int x, y, iCnt, rCnt;
  iCnt = rCnt = 0;
  PQMax left;
  PQMin right;

  while (true) {
    scanf(" %c", &c);
    if (c == 'p') {
      if (left.size() == 0) {
        printf("No Entry.\n");
      } else {
        printf("Middle member = %d\n", left.top());
      }
    } else if (c == 'i') {
      scanf(" %d", &x);
      if (iCnt == rCnt) {
        if (right.size() > 0 && x > right.top()) {
          left.insert(right.top());
          right.del();
          right.insert(x);
        } else {
          left.insert(x);
        }
        iCnt++;
      } else {
        if (x < left.top()) {
          right.insert(left.top());
          left.del();
          left.insert(x);
        } else {
          right.insert(x);
        }
        rCnt++;
      }
    } else if (c == 'd') {
      if (left.size() == 0) {
        printf("No Entry To Delete.\n");
      } else {
        y = left.top();
        left.del();
        if (iCnt > rCnt) {
          if (right.size() > 0) {
            left.insert(right.top());
            right.del();
          }
          iCnt--;
        } else {
          rCnt--;
        }
        printf("Middle Member = %d has been deleted.\n", y);
      }
    } else if (c == 'q') {
      break;
    }
  }
  return 0;
}