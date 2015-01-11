#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

constexpr int NBTHR= 10;

void hello(int a) {
  std::cout << "hello world! de " << a << std::endl;
  std::chrono::seconds d{5};
  std::this_thread::sleep_for(d);
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;
  std::vector<std::thread *> vtid(NBTHR);

  int i=0;
  for (auto &t: vtid) {
    t = new std::thread(hello, i++);
  }
  
  for (auto const t: vtid) {
    t->join();
  }
  
  return 0;
}
