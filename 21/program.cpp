#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

bool minPair(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

int minRoomNumbers(vector< pair<int, int> > schedules, int classes) {
  if(schedules.empty()) return 0;

  int rooms = 1;

  sort(schedules.begin(), schedules.end(), minPair);
  priority_queue<int> queue;
  queue.push(schedules[0].second);

  for(int i = 1; i < classes; i++) {
    if(schedules[i].first < queue.top()) {
      rooms++;
    } else {
      queue.pop();
    }
    queue.push(schedules[i].second);
  }

  return rooms;
}

int main() {
  return 0;
}
