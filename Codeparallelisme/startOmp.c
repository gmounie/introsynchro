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
#pragma omp single
    {
#pragma omp task
      {
	for(int i; i < NBTHR; i++) {
#pragma omp task
	  {
	    hello(i);
	  }
	}
	// l'attente fonctionne dans une task !
#pragma omp taskwait
      }
    }
  }
  return 0;
}
