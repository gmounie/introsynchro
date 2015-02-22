import std.stdio;
import std.concurrency;
import core.thread;

void hello(int i) {
  writeln("hello world! de ",i);
  stdout.flush();
  Thread.sleep(5.seconds);
}

int main() {
  foreach(i; 0..10) {
      spawn(&hello, i);
  }
  return 0;
}
