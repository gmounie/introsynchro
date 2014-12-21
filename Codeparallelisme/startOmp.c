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
      for(int i; i < NBTHR; i++) {
#pragma omp task
	{
	  hello(i);
	}
      }
      // l'attente est implicite en fin de bloc
#pragma omp taskwait
    } 
  }
  return 0;
}
