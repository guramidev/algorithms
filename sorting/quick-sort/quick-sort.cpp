#include <iostream>
using namespace std;

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int arr[], int start, int end) {
  int minPos = start - 1;
  int pi = end - 1;

  for(int i = start; i < end; i++) {
    if (arr[i] < arr[pi]) {
      minPos++;
      swap(&arr[i], &arr[minPos]);
    }
  }

  minPos++;
  swap(&arr[pi], &arr[minPos]);

  return minPos;
}

void quickSort(int arr[], int start, int end) {
  if (end - start == 0) return;

  int pi = partition(arr, start, end);

  quickSort(arr, start, pi);
  quickSort(arr, pi + 1, end);
}

void quickSort(int arr[], int size) {
  quickSort(arr, 0, size);
}

int main() {
  int size = 10;
  int arr[] = {88, 51, 28, 8, 54, 5, 84, 58, 45, 93};
  int arrSorted[10];
  cout << "Unsorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;

  quickSort(arr, size);

  cout << "Sorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;
}