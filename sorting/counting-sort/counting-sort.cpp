#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countSort(vector<int> &arr) {
  // initialize counter
  map<int, int> counter;
  int min = arr[0], max = arr[0];
  for (auto&& el: arr) {
    counter[el]++;
  }

  // replace arr elements with ordered ones using counter
  int k = 0;
  for(map<int, int>::iterator c = counter.begin(); c != counter.end(); c++) {
    for(int j = 0; j < c->second; j++) {
      arr[k] = c->first;
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