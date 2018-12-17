#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

// Random value from 0 to 1
double random() {
  return rand() / (RAND_MAX + 1.);
}

//
// An explanaiton of how the montecarlo method is used, is described in this
// website: https://academo.org/demos/estimating-pi-monte-carlo/
//
int main() {
  int inside = 0;
  for(int i = 0, i < 1000, i++) {
    double x = random(),
           y = random();
    if(x*x + y*y <= 1) inside++;
  }
  printf("%lf", 4.0 * inside / 1000);
  return 0;
}
