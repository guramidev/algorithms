#include <iostream>
#include <math.h>
using namespace std;

void insertionSort(int arr[], int size) {
  for(int i = 1; i < size; i++) {
    for(int j = i; j >= 0; j--) {
      if (arr[j] < arr[j - 1]) {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
      } else {
        break;
      }
    }
  }
}

int main() {
  int arr[] = {5, 2, 4, 3, 1};

  cout << "Unsorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;

  insertionSort(arr, 5);

  cout << "Sorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;
}