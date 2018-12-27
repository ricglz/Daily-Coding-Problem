#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define MAX 100

bool grid [MAX][MAX];
int rowSize, colSize;

struct Coord {
  int x;
  int y;
};

struct queueNode {
  Coord c;
  int dist;
};

bool isValid(int row, int col) {
  return row >= 0 && row < rowSize && col >= 0 && col < colSize;
}

int shortestPath(Coord source, Coord dest) {
  if(!(grid[source.x][source.y] && grid[dest.x][dest.y])) return -1;

  bool visited[MAX][MAX];
  memset(visited, false, sizeof visited);
  visited[source.x][source.y] = true;

  int rowNum [] = {-1, 0, 0, 1},
      colNum [] = {0, -1, 1, 0};

  queue<queueNode> q;
  queueNode s = {source, 0};
  q.push(s);
  while(!q.empty()) {
    queueNode curr = q.front();
    Coord coord = curr.c;

    if(coord.x == dest.x && coord.y == dest.y) return curr.dist;

    q.pop();
    int newDist = curr.dist + 1;

    for(int i = 0; i < 4; i++) {
      int row = coord.x + rowNum[i];
      int col = coord.y + colNum[i];

      if(isValid(row, col) && !(grid[row][col] && visited[row][col])) {
        visited[row][col] = true;
        queueNode newCell = { { row, col }, newDist };
        q.push(newCell);
      }
    }
  }
  return INT_MAX;
}

int main() {
  cin >> rowSize >> colSize;
  for(int i = 0; i < rowSize; i++) {
    for(int j = 0; j < colSize; j++) {
      cin >> grid[i][j];
    }
  }
  Coord source, dest;
  cin >> source.x >> source.y >> dest.x >> dest.y;
  cout << shortestPath(source, dest) << endl;
  return 0;
}
