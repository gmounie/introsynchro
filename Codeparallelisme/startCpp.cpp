#include <iostream>
#include <thread>
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
  vector<thread *> vtid(NBTHR);

  int i=0;
  for (auto &t: vtid) {
    t = new thread(hello, i++);
  }

  for (auto const t: vtid) {
    t->join();
  }

  return 0;
}
