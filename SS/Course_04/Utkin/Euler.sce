a = input('a: ');
b = input('b: ');
h = input('h: ');
y0 = input('y(a): ');
absErr = 0;

for x = a:h:(b - h)
  y0 = y0 + h * ((x + h) * cos(x + h) + y0/(x + h));
  y = (x + h) * sin(x + h);
  absErr = max(absErr, abs(y-y0));
  printf('x: %f, ny: %f, y: %f, delta: %f\n', x+h, y0, y, abs(y-y0));
end

printf('DELTA: %f', absErr);
