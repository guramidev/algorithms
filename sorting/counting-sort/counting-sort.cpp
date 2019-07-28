#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countSort(vector<int> &arr) {
  // initialize counter
  map<int, int> counter;
  for (auto&& el: arr) {
    counter[el]++;
  }

  // replace arr elements with ordered ones using counter
  int k = 0;
  for(auto&& [value, occurrenceCount]: counter) {
    for(int j = 0; j < occurrenceCount; j++) {
      arr[k] = value;
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