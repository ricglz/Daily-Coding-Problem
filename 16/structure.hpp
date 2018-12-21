#include <vector>

using namespace std;

class OrdersLog {
  public:
    OrdersLog(int);
    void record(int);
    vector<int> getLast(int);

  private:
    vector<int> elements;
};

OrdersLog::OrdersLog(int initialSize) {
  for(int i = 1; i <= initialSize; i++) {
    elements.push_back(i);
  }
}

void OrdersLog::record(int newRecord) {
  elements.push_back(newRecord);
}

vector<int> OrdersLog::getLast(int position) {
  if(position <= 0 || position > elements.size()) {
    return vector<int>();
  }
  return vector<int>(elements.end() - position, elements.end());
}

