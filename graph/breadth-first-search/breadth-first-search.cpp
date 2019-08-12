#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;

vector<int> bfs(int start, map<int, vector<int>> const *graph, int vertexCount) {
  vector<int> traverseOrder;
  vector<bool> visited(vertexCount, false);
  list<int> queue;

  visited[start] = true;
  queue.push_back(start);

  list<int>::iterator i;
  while(!queue.empty()) {
    start = queue.front();
    queue.pop_front();
    traverseOrder.push_back(start);
    for(auto&& vertex : graph->at(start)) {
      if (!visited[vertex]) {
        visited[vertex] = true;
        queue.push_back(vertex);
      }
    }
  }

  return traverseOrder;
}

int main() {
  map<int, vector<int>> graph;
  graph[0] = vector<int>{1, 2, 3};
  graph[1] = vector<int>{0, 2, 4, 5};
  graph[2] = vector<int>{1, 4, 6};
  graph[3] = vector<int>{4, 5};
  graph[4] = vector<int>{1, 2, 3};
  graph[5] = vector<int>{1, 3};
  graph[6] = vector<int>{2};

  vector<int> traversal = bfs(0, &graph, 7);

  for(auto&& vertex: traversal) {
    cout << vertex << " ";
  }
}

