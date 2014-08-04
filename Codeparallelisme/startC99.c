#include <stdio.h>
#include <pthread.h>

void *hello(void *a) {
  printf ("hello world! de %ld\n", (long)a);
  return 0;
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;
  pthread_t tid[2];
  
  for (int i=0; i < 2; i++) {
    pthread_create(& tid[i], NULL, hello, (void *)(long)i);
  }
  
  for (int i=0; i < 2; i++) {
    void *status;
    pthread_join(tid[i], & status);
  }
  
  return 0;
}
