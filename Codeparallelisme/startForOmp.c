#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NBTHR 10

void hello(int a) {
  printf ("hello world! de %d\n", a);
  sleep(5);
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;

#pragma omp parallel
  {
#pragma omp for
    for(int i=0; i < NBTHR; i++) {
      hello(i);
    }
  }
  return 0;
}
