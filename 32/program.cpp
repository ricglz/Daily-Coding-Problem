#include <iostream>
#include <cmath>
#include <vector>
#include <cfloat>

using namespace std;

int min(int a, int b) {
  if(a < b) return a;
  return b;
}

bool arbitrage(vector<vector<double> > table) {
  int n = table.size();
  vector<vector<double> > transformed_graph(n);

  for(int i = 0; i < n; i++) {
    for(double edge : table[i]) {
      transformed_graph[i].push_back(-1*log(edge));
    }
  }

  int source = 0;
  double min_dist[n];
  for(int i = 0; i < n; i++) {
    min_dist[i] = DBL_MIN;
  }

  min_dist[source] = 0;

  for(int i = 0; i < n - 1; i++) {
    for(int v = 0; v < n; v++) {
      for(int w = 0; w < n; w++) {
        min_dist[w] = min(min_dist[w], min_dist[v] + transformed_graph[v][w]);
      }
    }
  }

  for(int v = 0; v < n; v++) {
    for(int w = 0; w < n; w++) {
      if(min_dist[w] > min_dist[v] + transformed_graph[v][w]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  return 0;
}
