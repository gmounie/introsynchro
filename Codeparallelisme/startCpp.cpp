#include <iostream>
#include <thread>

void hello(int a) {
  std::cout << "hello world! de " << a << std::endl;
}

int main(int argc, char **argv) {
  (void)argc;
  (void) argv;
  std::thread *tid[2];
  
  for (int i=0; i < 2; i++) {
    tid[i] = new std::thread(hello, i);
  }
  
  for (int i=0; i < 2; i++) {
    tid[i]->join();
  }
  
  return 0;
}


