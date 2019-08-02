#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end, int sorted[]) {
  for(int l = start, r = mid, k = start; !(l == mid && r == end); k++) {
    if (l == mid || (r < end && arr[r] < arr[l])) {
      sorted[k] = arr[r];
      r++;
    } else {
      sorted[k] = arr[l];
      l++;
    }
  }

  for(int i = start; i < end; i++) {
    arr[i] = sorted[i];
  }
}

void mergeSort(int arr[], int start, int end, int sorted[]) {
  int size = end - start;
  if (size == 1) return;

  int mid = (size / 2) + start;

  mergeSort(arr, start, mid, sorted);
  mergeSort(arr, mid, end, sorted);

  merge(arr, start, mid, end, sorted);
}

void mergeSort(int arr[], int size) {
  int *sorted = new int[size];
  mergeSort(arr, 0, size, sorted);
  delete[] sorted;
}

int main() {
  int size = 10;
  int arr[] = {88, 93, 28, 51, 54, 5, 84, 58, 45, 8};
  int arrSorted[10];
  cout << "Unsorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;

  mergeSort(arr, size);

  cout << "Sorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;
}