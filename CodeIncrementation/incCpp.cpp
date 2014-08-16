#include <thread>
#include <iostream>
#include <array>
#include <mutex>
#include <atomic>
#include <chrono>

using namespace std;

static const int NBINC= 2000; // sur mon core-i7, suffisant pour compter faux

// qui marche pas
int compteur=0;

// avec un mutex
mutex m;
int compteurl =0;

// avec des operations atomiques (entier)
atomic<int> compteura;

void hello(int *c, int stride) {
  //  cout << "coucou de " << std::this_thread::get_id() << endl;
  for (int i = 0; i < NBINC; ++i)
    (*(c+stride*i))++; 
}

void hellol(int *c, int stride) {
  for (int i = 0; i < NBINC; ++i)
    {
      lock_guard<mutex> garde(m);
      (*(c+stride*i))++; 
    }
}

void helloa(atomic<int> *c, int stride) {
  for (int i = 0; i < NBINC; ++i)
    (*(c+stride*i))++; // ++ atomic
}
  
template< class Function, class countp > 
double QuatreThreads(Function &&f, countp c, int stride) {
  auto start = chrono::system_clock::now(); 
  array<thread, 4> threads = { thread(f, c, stride), thread(f, c, stride), thread(f, c, stride),
			       thread(f, c, stride)};

  for(auto & th: threads ) {
    th.join();
  }
  auto end = chrono::system_clock::now();
  return chrono::duration<double>(end - start).count();
}

int main(int argc, char **argv) {
  int stride = 0;
  if (argc == 42) stride = atoi(argv[1]); // pour forcer les boucles
					 // malgré les optimisations,
					 // ne jamais mettre
					 // d'arguments, il faut un
					 // stride de 0 !

  double t = QuatreThreads(hello, &compteur, stride);
  cout << "compteur: " << compteur << " en " << t << " s" << endl;

  t = QuatreThreads(hellol, &compteurl, stride);
  cout << "compteur avec lock: " << compteurl << " en " << t << " s"  << endl;

  compteura.store(0);
  t = QuatreThreads(helloa, &compteura, stride);
  cout << "compteur atomic: " << compteura << " en " << t << " s"  << endl;
  return 0;

}
