#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
using namespace std;

void shellSort(int arr[], int size, vector<int> gaps) {
  int i, j;

  for(auto&& gap: gaps) {
    for(i = gap; i < size; i++) {

      int temp = arr[i];
      for(j = i; j >= gap && arr[j - gap] > temp; j-=gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;

    }
  }
}

vector<int> getShellStrategy(int size, int k) {
  vector<int> strategy;

  while(size > 1) {
    size = size / pow(2, k);
    strategy.push_back(size);
  }

  return strategy;
}

int main() {
  int size = 20;
  int arr[] = {32, 22, 88, 47, 66, 52, 94, 39, 74, 61, 85, 10, 81, 77, 23, 55, 19, 87, 34, 46};

  map<string, vector<int>> strategies;
  strategies["Shell Strategy"] = getShellStrategy(size, 1);

  cout << "Unsorted array: ";
  for (auto&& el: arr) cout << el << " ";
  cout << endl;

  for(auto&& [strategyName, strategy]: strategies) {
    cout << "Sorting using \"" << strategyName << "\" -> ";

    shellSort(arr, size, strategy);

    for (auto&& el: arr) cout << el << " ";
    cout << endl;
  }
}