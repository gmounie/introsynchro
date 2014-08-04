#include <stdio.h>
#include <cilk/cilk.h>

void hello(int a) {
  printf ("hello world! de %d\n", a);
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;
  
  for (int i=0; i < 2; i++) {
    cilk_spawn hello(i);
  }
  
  cilk_sync;
  return 0;
}
