function Q2(img, k)
  [lin, col, ~] = size(img);
  nimg = zeros(lin, col);
  
  nimg(k:lin, k:col) = img(1:lin-k+1, 1:col-k+1);
  
  nimg = img - nimg;

imshow(nimg);