#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <stack>
using namespace std;

/**
 * @param start
 * @param graph
 * @param vc - vertex count
 * @return
 */
vector<int> dfs(int start, map<int, vector<int>> *graph, int vc) {
  vector<int> traversalOrder;
  vector<bool> visited(vc, false);
  stack<int> stack;
  stack.push(start);

  while (!stack.empty()) {
    start = stack.top();
    stack.pop();

    if (!visited[start]) {
      traversalOrder.push_back(start);
      visited[start] = true;
    }

    for(auto&& vertex: graph->at(start)) {
      if (!visited[vertex])
        stack.push(vertex);
    }
  }

  return traversalOrder;
}

int main() {
  map<int, vector<int>> graph;
  graph[0] = vector<int>{2, 3};
  graph[1] = vector<int>{0, 4};
  graph[2] = vector<int>{1};
  graph[3] = vector<int>{};
  graph[4] = vector<int>{};

  vector<int> traversal = dfs(0, &graph, 5);

  for(auto&& vertex: traversal) {
    cout << vertex << " ";
  }
}

