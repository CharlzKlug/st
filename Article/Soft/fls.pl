#!/usr/bin/perl
use strict;

my $str = $ARGV[0];
#print $str . "\n";
my @flist = glob $ARGV[0];
print "$_\n" for(@flist);
