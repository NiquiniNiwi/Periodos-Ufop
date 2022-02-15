function T = Q2(i)
  id = im2double(i);
  [lin, col, ~] = size(i);
  T = 0;
  for i = 1: lin
    for j =1: col
      T = T + id(i,j);
    endfor
  endfor
  T = T/(lin * col);
  
  contG1 = 0;
  contG2 = 0;
  G1 = 0;
  G2 = 0;
  Nt = 0;
  Kt = T;
  do
    T = Kt;
      for i = 1: lin
        for j =1: col
          if T > id(i,j)
            contG1 = contG1 + 1;
            G1 = G1 + id(i,j);
          else
            contG2 = contG2 + 1;
            G2 = G2 + id(i,j);
          endif
        endfor
      endfor
    u1 = G1/contG1;
    u2 = G2/contG2;
    Nt = (u1 + u2) / 2;
    Kt = Nt;
  until ((Nt - T) < 0.0010)

  imshow(id > T);
  return;