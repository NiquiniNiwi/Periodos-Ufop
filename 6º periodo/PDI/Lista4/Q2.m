function [vermelho, azul, verde, magenta, RGB]=Q2(img, mask)
  [lin, col, ~] = size(img);
  RGB = zeros(lin, col, 3);
  azul = 0;
  magenta = 0;
  verde = 0;
  vermelho = 0;
  for i = 1 : lin
    for j = 1 : col
      if img(i,j)<=63
        azul = azul + 1;
        RGB(lin, col, 1) = 0;
        RGB(lin, col, 2) = 0;
        RGB(lin, col, 3) = 255;
      else if img(i,j) <= 127
        magente = magenta +1;
        RGB(lin, col, 1) = 255;
        RGB(lin, col, 2) = 0;
        RGB(lin, col, 3) = 255;
      else if img(i,j) <=191
        verde = verde +1;
        RGB(lin, col, 1) = 0;
        RGB(lin, col, 2) = 255;
        RGB(lin, col, 3) = 0;
       else
        vermelho = vermelho +1;
        RGB(lin, col, 1) = 255;
        RGB(lin, col, 2) = 0;
        RGB(lin, col, 3) = 0;
       endif
     endif
   endif
    endfor
  endfor
  R = RGB(:,:,1);
  G = RGB(:,:,2);
  B = RGB(:,:,3);
  RGB = cat(3, G, R, B);