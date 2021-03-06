#!/usr/bin/perl
use Image::Magick;
use strict;

# The class of Color
package Color;
use Moose;

has 'red' => (
    is => 'rw',
    isa => 'Num');

has 'blue' => (
    is => 'rw',
    isa => 'Num');

has 'green' => (
    is => 'rw',
    isa => 'Num');
no Moose;

# The class of Point
package Point;
use Moose;
has 'x' => (
    is => 'rw',
    isa => 'Num');

has 'y' => (
    is => 'rw',
    isa => 'Num');
no Moose;

# The class of Vector
package Vector;
use Moose;
has 'x' => (
    is => 'ro',
    isa => 'Num');

has 'y' => (
    is => 'ro',
    isa => 'Num');

around BUILDARGS => sub {
    my ($orig, $class, $pointA, $pointB) = @_;
    $class->$orig('x' => $pointB->x - $pointA->x, 'y' => $pointB->y - $pointA->y);
};

no Moose;

__PACKAGE__->meta->make_immutable;

#my $tVr = Vector->new(Point->new(x => 3, y => 4), Point->new(x => 5, y => 7));

#print "Test Vector x: " . $tVr->x . ", y: " . $tVr->y . "\n";
my $colorA = getMiddleColor($ARGV[0]);
my $colorB = getMiddleColor($ARGV[1]);

print "\$colorA Red: " . $colorA->red . ", Green: " . $colorA->green . ", Blue: " . $colorA->blue . "\n";
print "\$colorB Red: " . $colorB->red . ", Green: " . $colorB->green . ", Blue: " . $colorB->blue . "\n\n";

my $fileMask = $ARGV[2];
my @flist = glob $fileMask;
my $timeStep = 1;
my $time = 0;
my $previousVector = Vector->new(Point->new(x => 0, y =>0), Point->new(x => 0, y => 0));
for(@flist){
    print "Processing " . $_ . "\n";
    my $vctr = makeVector($colorA, $colorB, 0.05, $_);
    print "Time mark: " . $time . "\n";
    print "Prev vector's x: " . $previousVector->x . ", y: " . $previousVector->y . "\n";
    print "Vector's x: " . $vctr->x . ", y: " . $vctr->y . "\n";
    
    if ($time != 0){
	print directedVolume($previousVector, $vctr) . "\n";
	print calcAngle($previousVector, $vctr) . "\n";
    }

    $previousVector = $vctr;
    $time += $timeStep;
    print "\n";
}

sub getMiddleColor {
    my $foo = Image::Magick->new;
    $foo->Read($_[0]);
    my $x = $foo->Get('columns');
    my $y = $foo->Get('rows');
    my @pixels;
    my $red = 0;
    my $green = 0;
    my $blue = 0;
    for(my $i=0; $i<$x; $i++){
	for(my $j = 0; $j < $y; $j++){
	    @pixels = $foo->GetPixel(x => $i, y => $j);
	    $red += $pixels[0];
	    $green += $pixels[1];
	    $blue += $pixels[2];
	}
    }
    my $pixelsCount = $x * $y;
    $red /= $pixelsCount;
    $green /= $pixelsCount;
    $blue /= $pixelsCount;
    return Color->new(red => $red, green => $green, blue => $blue);
}

sub getColorCenter {
    my $color = $_[0];
    my $px = 0;
    my $py = 0;
    my $picture = Image::Magick->new;
    $picture->Read($_[1]);
    my $ix = $picture->Get('columns');
    my $iy = $picture->Get('rows');
    my @pixels;
    my $apprPoints = 0;
    my $threshold = 0.05;
    for(my $i = 0; $i < $ix; $i++){
	for(my $j = 0; $j < $iy; $j++){
	    @pixels = $picture->GetPixel(x => $i, y => $j);
	    if (abs($color->red - $pixels[0]) < $threshold
		&& abs($color->green - $pixels[1]) < $threshold
		&& abs($color->blue - $pixels[2]) < $threshold){
		$px += $i; $py += $j; $apprPoints++;
	    }
	}
    }
    $px /= $apprPoints;
    $py /= $apprPoints;
    return Point->new(x => $px, y => $py);
}

sub makeVector {
    my $colorA = $_[0];
    my $colorB = $_[1];
    my $threshold = $_[2];
    my $picture = Image::Magick->new;
    $picture->Read($_[3]);
    my $width = $picture->Get('columns');
    my $height = $picture->Get('rows');
    my @pixels;
    my $APointCount = 0;
    my $BPointCount = 0;
    my $APoint = Point->new(x => 0, y => 0);
    my $BPoint = Point->new(x => 0, y => 0);
    for(my $i = 0; $i < $width; $i++){
	for(my $j = 0; $j < $height; $j++){
	    @pixels = $picture->GetPixel(x => $i, y => $j);
	    if (abs($colorA->red - $pixels[0]) < $threshold
		&& abs($colorA->green - $pixels[1]) < $threshold
		&& abs($colorA->blue - $pixels[2]) < $threshold){
		$APoint->x($APoint->x + $i);
		$APoint->y($APoint->y + $j);
		$APointCount++;
	    }
	    if (abs($colorB->red - $pixels[0]) < $threshold
		&& abs($colorB->green - $pixels[1]) < $threshold
		&& abs($colorB->blue - $pixels[2]) < $threshold){
		$BPoint->x($BPoint->x + $i);
		$BPoint->y($BPoint->y + $j);
		$BPointCount++;
	    }
	}
    }
    $APoint->x($APoint->x / $APointCount);
    $APoint->y($APoint->y / $APointCount);
    $BPoint->x($BPoint->x / $BPointCount);
    $BPoint->y($BPoint->y / $BPointCount);
    return Vector->new($APoint, $BPoint);
}

sub directedVolume{
    my $vector1 = $_[0];
    my $vector2 = $_[1];
    return ($vector1->x * $vector2->y) - ($vector2->x * $vector2->y);
}

sub calcAngle{
    use Math::Trig;
    my $vector1 = $_[0];
    my $vector2 = $_[1];
    #return acos(1);
    return rad2deg(acos(($vector1->x * $vector2->x + $vector1->y * $vector2->y) / (sqrt($vector1->x * $vector1->x + $vector1->y * $vector1->y) *
										   sqrt($vector2->x * $vector2->x + $vector2->y * $vector2->y))));
}
