#include <thread>
#include <cassert>
#include <iostream>
#include <future>
#include <sstream>

long long int fibo(int n) {
  if (n < 2)
    return 1;

  auto res1 = std::async(fibo, n-1);
  long long int res2 = fibo(n-2);
  return res1.get() + res2;
}

int main(int argc, char **argv) {
  assert(argc == 2);
  std::istringstream istr(argv[1]);
  int n;
  istr >> n;
  auto start = std::chrono::high_resolution_clock::now();
  long long int resu = fibo(n);
  auto end = std::chrono::high_resolution_clock::now();
  double temps = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "fibo(" << n << ")" << " = " << resu << " en " << temps/1000. << "s" << std::endl;
}
