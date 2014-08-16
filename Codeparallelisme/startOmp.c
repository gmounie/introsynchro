#include <stdio.h>
#include <pthread.h>

void hello(int a) {
  printf ("hello world! de %d\n", a);
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;

#pragma omp parallel
  {
#pragma omp single
    {
#pragma omp task
      {
	hello(0);
      }
#pragma omp task
      {
	hello(1);
      }
      // l'attente est implicite en fin de bloc
      // #pragma omp taskwait
    } 
  }
  return 0;
}
