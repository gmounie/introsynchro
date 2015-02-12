use v5.20;
use threads;

sub hello {
  my $num = shift;
  say "Hello from $num";
  sleep 5;
}

my @thr;

for my $i  (0..10) {
  push @thr, threads->create( sub { hello $i } );
}

for my $t (@thr) {
  $t->join();
}

