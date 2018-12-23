a = input('a: ');
b = input('b: ');
h = input('h: ');
y0 = input('y(a): ');
absErr = 0;

for x = a:h:(b - h)
  k1 = x * cos(x) + y0 / x;
  k2 = (x + h / 2) * cos(x + h / 2) + (y0 + h * k1 / 2) / (x + h / 2);
  k3 = (x + h / 2) * cos(x + h / 2) + (y0 + h * k2 / 2) / (x + h / 2);
  k4 = (x + h) * cos(x + h) + (y0 + h * k3) / (x + h);
  y0 = y0 + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
  y = (x + h) * sin(x + h);
  absErr = max(absErr, abs(y-y0));
  printf('x: %f, ny: %f, y: %f, delta: %f\n', x+h, y0, y, abs(y-y0));
end

printf('DELTA: %f', absErr);
