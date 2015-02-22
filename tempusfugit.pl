#!/usr/bin/perl -w

use v5.20;

my $debut = time;
while (my $ligne = <>)
  {
	  chomp $ligne;
	  my $maintenant = time - $debut;
	  say  "$maintenant: ".$ligne;
  }
