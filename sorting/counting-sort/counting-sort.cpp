#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countSort(vector<int> &arr) {
  int min = arr[0], max = arr[0];

  for (auto&& el: arr) {
    if (el < min) {
      min = el;
    } else if (el > max) {
      max = el;
    }
  }

  int size = max - min + 1;
  int *counter = new int[size]{};

  for(auto&& el: arr) {
    counter[el - min]++;
  }

  // use counter to replace arr elements in correct order
  for(int i = 0, k = 0; i < size; i++) {
    for(int j = 0; j < counter[i]; j++) {
      arr[k] = i + min;
      k++;
    }
  }
}

int main() {
  int a[] = {5, 10, 3, 99, 5};
  vector<int> arr(a,  a + sizeof(a) / sizeof(int) );

  cout << "Unsorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;

  countSort(arr);

  cout << "Sorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;
}