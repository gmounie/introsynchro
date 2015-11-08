#include <stdio.h>
#include <stdint.h>
#include <cilk/cilk.h>
#include <stdlib.h>
#include <time.h>

int64_t fibo(int64_t n) {
  int64_t y = 0;
  if (n < 2) return 1;

  int64_t x = cilk_spawn fibo(n-1);
  y = cilk_spawn fibo(n-2);
  
  cilk_sync;

  return x+y;
}

int main(int argc, char **argv) {
  struct timespec start, end;
  
  clock_gettime(CLOCK_REALTIME, & start);
  long long int result = fibo(atoi(argv[1]));
  clock_gettime(CLOCK_REALTIME, & end);

  double temps = end.tv_sec - start.tv_sec +
    (end.tv_nsec - start.tv_nsec)*1.e-9;
  printf("%Ld en %g s\n",result, temps);

  return 0;
}
