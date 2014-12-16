#include <stdio.h>
#include <stdint.h>
#include <cilk/cilk.h>

int64_t fibo(int64_t n) {
  if (n < 2) return n;
  int64_t x = cilk_spawn fibo(n-1);
  int64_t y = fibo(n-2);
  cilk_sync;
  return x+y;
}

int main(int argc, char **argv) {
  int result = fibo(atoi(argv[1]));
  printf("%Ld\n",result);
}
