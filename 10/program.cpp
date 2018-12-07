#include <cunistd>

void f(int n) {
  /* Some code */
  usleep(n);
  f(n);
}
