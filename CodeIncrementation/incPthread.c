#include <pthread.h>
#include <stdio.h>
#include <stdatomic.h>
#include <time.h>
#include <stdlib.h>

static const int NBINC= 1000; // sur mon core-i7, suffisant pour compter faux

// qui marche pas
int compteur=0;

// avec un mutex
pthread_mutex_t m;
int compteurl =0;

// avec des operations atomiques (entier) de C11
atomic_int compteura;

// stride pour embeter le compilateur
int stride = 0;


void hello(int *c) {
  for (int i = 0; i < NBINC; ++i)
    (*(c+stride*i))++; 
}

void hellol(int *c) {
  for (int i = 0; i < NBINC; ++i)
    {
      pthread_mutex_lock(&m);
      (*(c+stride*i))++; 
      pthread_mutex_unlock(&m);
    }
}

void helloa(atomic_int *c) {
  for (int i = 0; i < NBINC; ++i)
    atomic_fetch_add((c+stride*i), 1); // ++ atomic
}
  

void *lanceur(void *arg) {
  long i = (long)arg;

  switch(i) {
  case 0:
    hello(& compteur);
    break;
  case 1:
    hellol( & compteurl);
    break;
  case 2:
    helloa(& compteura);
    break;
  }
  return 0;
}


double QuatreThreads(long type) {
  pthread_t th[4];
  struct timespec start, end;

  clock_gettime(CLOCK_REALTIME, & start);
  for(int i=0; i < 4; i++) {
    pthread_create(& th[i], 0, lanceur, (void *)type);
  }

  for(int i=0; i < 4; i++) {
    void * result;
    pthread_join(th[i], & result);
  }
  clock_gettime(CLOCK_REALTIME, & end);

  double temps = end.tv_sec - start.tv_sec +
    (end.tv_nsec - start.tv_nsec)*1.e-9;

  return temps;
}



int main(int argc, char **argv) {
  if (argc == 42) stride = atoi(argv[1]); // pour forcer les boucles
					 // malgré les optimisations,
					 // ne jamais mettre
					 // d'arguments, il faut un
					 // stride de 0 !

  atomic_init(&compteura, 0);
  

  double t = QuatreThreads(0);
  printf("compteur: %d en %g\n", compteur, t);

  t = QuatreThreads(1);
  printf("compteur avec lock: %d en %g\n", compteurl, t);

  t = QuatreThreads(2);
  printf("compteur atomic: %d en %g\n", compteura, t);
  return 0;

}
