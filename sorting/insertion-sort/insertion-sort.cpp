#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
  int i, j;

  for(i = 1; i < size; i++) {

    int temp = arr[i];
    for(j = i; j >= 0 && arr[j - 1] > temp; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = temp;

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