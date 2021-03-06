disp('Fourth grade Runge-Kutta''s method.');
a = input('Enter lowest bound: ');
b = input('Enter highest bound: ');
h = input('Enter step: ');
y0 = input('Enter y0: ');
absErr = 0;

for x = a:h:(b - h)
  k1 = - x / y0;
  k2 = - (x + h / 2) / (y0 + h * k1 / 2);
  k3 = - (x + h / 2) / (y0 + h * k2 / 2);
  k4 = - (x + h) / (y0 + h * k3);
  y0 = y0 + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
  y = sqrt(4 - (x+h)^2);
  absErr = max(absErr, abs(y-y0));
  printf('x: %f, RK: %f, y: %f, error: %f\n', x+h, y0, y, abs(y-y0));
end

printf('Max error: %f', absErr);
