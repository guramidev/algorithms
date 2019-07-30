#include <iostream>
#include <queue>
using namespace std;

void heapSort(int arr[], int size) {
  int i = 0, k = 0;
  priority_queue< int, vector<int>, greater<int> > min_heap;

  for(i = 0; i < size; i ++) {
    min_heap.push(arr[i]);
  }

  while(!min_heap.empty()) {
    arr[k] = min_heap.top();
    min_heap.pop();
    k++;
  }
}

int main() {
  int size = 10;
  int arr[] = {88, 93, 28, 51, 54, 5, 84, 58, 45, 8};

  cout << "Unsorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;

  heapSort(arr, size);

  cout << "Sorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;
}