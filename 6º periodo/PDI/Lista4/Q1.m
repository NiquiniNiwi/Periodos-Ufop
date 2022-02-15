function nimg = Q1( img , n )
  [lin, col, ~] = size(img);
  nimg = zeros (lin, col) ;
  figs =  zeros(lin, col , n ) ;
  for k = 1: n
    for i = 1 : lin
      for j = 1: col
        figs (i, j, k) = im2double(imnoise(img, "gaussian"))(i, j) ;
      end    
    end
  end
    sort(figs,3);
    nimg = uint8(figs{round(n/2)});
end