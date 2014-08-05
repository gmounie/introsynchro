import std.stdio;
import std.concurrency;
import core.thread;

void hello(int i) {
  writeln("hello world! de ",i);
  Thread.sleep(5.seconds);
}

int main() {
  foreach(i; 0..2) {
      spawn(&hello, i);
  }
  return 0;
}
