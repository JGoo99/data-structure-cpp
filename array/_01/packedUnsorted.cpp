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
    cout << "Array is full." << endl;
  }
}

void del(int index) {
  A[index] = A[S - 1];
  S--;
}

void print() {
  // 인덱스
  for (int j = 0; j < S; j++) {
    cout << setw(3) << j << "   ";
  }
  cout << endl;
  // 요소
  for (int j = 0; j < S; j++) {
    cout << setw(3) << A[j] << "   ";
  }
  cout << endl;
}

int main() {
  char c;
  int x;

  while (true) {
    cout << "Size: " << S << endl;
    print();

    cin >> c;
    if (c == 'F') {
      cout << "<<<<<< Find >>>>>>" << endl;
      cout << "Enter value to find: ";

      cin >> x;
      int index = indexOf(x);
      if (index == -1) {
        cout << x << " Not Found" << endl;
      } else {
        cout << x << " Found At Index " << index << endl;
      }
    }
    else if (c == 'I') {
      cout << "<<<<<< Insert >>>>>>" << endl;
      cout << "Enter value to insert: ";

      cin >> x;
      if (indexOf(x) == -1) {
        insert(x);
      }
    }
    else if (c == 'D') {
      cout << "<<<<<< Delete >>>>>>" << endl;
      cout << "Enter value to delete: ";

      cin >> x;
      int index = indexOf(x);
      if (index == -1) {
        cout << x << " Not Found" << endl;
      } else {
        del(index);
      }
    }
    else if (c == 'Q') {
      cout << "<<<<<< Quit >>>>>>" << endl;
      break;
    }
    else {
      cout << "Retry [F:find, I:insert, D:delete, Q:quit]" << endl;
    }
  }
  return 0;
}
