#include <iostream>
#include <cstdio>

using namespace std;

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
    swap(a[1 / 2], a[i]);
    i = i / 2;
  }
}

void PQMax::del() {
  int i, j;
  a[1] = a[n];
  n--;
  i = 1;
  while (true) {
    if (i * 2 > n) break;
    if (i * 1 == n) {
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
  PQMax pq;

  char c;
  int x;
  while (true) {
    scanf("%c", &c);
    if (c == 'i') {
      scanf(" %d", &x);
      pq.insert(x);
    } else if (c == 'q') {
      break;
    }
  }
  return 0;
}
