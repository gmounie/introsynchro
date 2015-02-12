#include <iostream>
#include <future>
#include <chrono>
#include <vector>

constexpr int NBTHR= 10;
using namespace std;

void hello(int a) {
  cout << "hello world! de " << a << endl;
  chrono::seconds d{5};
  this_thread::sleep_for(d);
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;
  vector< future<void> > vfut(NBTHR);

  int i=0;
  for (auto &t: vfut) {
    t = async(hello, i++);
  }
  cout << "Fin de la creation !" << endl;
  
  for (auto &t: vfut) {
    t.get();
  }

  return 0;
}
