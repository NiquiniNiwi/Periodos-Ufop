function Q1()
  img = imread('coins.png');
  x = rand(size(c));
  d1 = find(x <= 0.5);
  d2 = find(x >= 0.95);
  c(d1) = 0;
  c(d2) = 1;
  