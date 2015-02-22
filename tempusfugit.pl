#!/usr/bin/perl -w

use v5.20;

my $debut = time;
while (my $ligne = <STDIN>)
  {
	  chomp $ligne;
	  my $maintenant = time - $debut;
	  say  "$maintenant: ".$ligne;
  }
