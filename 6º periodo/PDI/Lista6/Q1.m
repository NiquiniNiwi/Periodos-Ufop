function Q1(i)
  id = im2double(i);
  [lin, col, ~] = size(i);
  im = zeros(lin, col);
  for i = 1 : lin
    for j = 1 : col
      im(i,j) = id(i,j);
    endfor
  endfor