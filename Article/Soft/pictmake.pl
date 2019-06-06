#!/usr/bin/perl
use strict;

my $xc = 150;
my $yc = 125;
my $step = 0.01;
my $radius = 75;
my $count = 0;
for(my $angle = 0; $angle < 6.28; $angle += $step){
    $count++;
    my $x = $xc + $radius * sin($angle);
    my $y = $yc - $radius * cos($angle);
    my $cmd = "convert -size 300x250 xc:white -draw 'fill blue circle " . $xc . ", " . $yc . ", " . ($xc + 10) . ", " . $yc . " fill red circle " . $x . ", " . $y . ", " . ($x + 10) . ", " . $y . "' photo_" . sprintf("%03d", $count) . ".jpg";
    print "Doing file: photo_" . sprintf("%03d", $count) . ".jpg\n";
    system($cmd);
}
