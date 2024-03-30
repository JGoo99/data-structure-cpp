#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_SIZE 100

int A[MAX_SIZE];
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
  return insertPosition;
}

void insert(int x) {
  if (S == MAX_SIZE) {
    cout << "Array is full." << endl;
    return;
  }

  int insertPosition = findInsertPosition(x);

  for (int i = S; i > insertPosition; i--) {
    A[i] = A[i - 1];
  }
  A[insertPosition] = x;
  S++;
}

void del(int index) {
  for (int i = index; i < S - 1; i++) {
    A[i] = A [i + 1];
  }
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
  // 마커 (0:none, 1:fill)
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
