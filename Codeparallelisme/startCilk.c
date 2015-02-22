#include <stdio.h>
#include <cilk/cilk.h>
#include <unistd.h>

#define NBTHR 10

void hello(int a) {
  printf ("hello world! de %d\n", a);
  fflush(stdout);
  sleep(5);
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;
  
  for (int i=0; i < NBTHR; i++) {
    cilk_spawn hello(i);
  }
  
  cilk_sync;
  return 0;
}
