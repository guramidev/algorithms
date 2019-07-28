#include <iostream>
#include <math.h>
using namespace std;

void radixSort(int arr[], int size) {
  int base = size;
  double k = pow(size, 2);
  
  for (int i = 1; i < k; i *= base) {
    int count[base];
    for(int j = 0; j < base; j++) count[j] = 0;
    for(int j = 0; j < size; j++) {
      count[(arr[j]/i)%base]++;
    }

    for(int j = 1; j < base; j++) count[j] += count[j-1];

    int tempArr[size];
    for(int j = size - 1; j >= 0; j--) {
      tempArr[count[(arr[j]/i)%base] - 1] = arr[j];
      count[(arr[j]/i)%base]--;
    }

    for(int j = 0; j < size; j++) arr[j] = tempArr[j];
  }
}

int main() {
  int arr[] = {5, 2, 4, 3, 1};

  cout << "Unsorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;

  radixSort(arr, 5);

  cout << "Sorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;
}