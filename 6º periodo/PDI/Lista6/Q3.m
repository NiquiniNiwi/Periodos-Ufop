function Q3(t)
  t = rgb2gray(t);
##error: rgb2gray: RGB of invalid data type 'logical'
##                      error: called from
##    colorspace_conversion_input_check at line 41 column 7
##    rgb2gray at line 61 column 5
##    Q3 at line 3 column 5
## Não fui capaz de resolver esse problema
  [lin, col] = size(t);
  [x,y] = meshgrid(1:lin, 1:col);
  t2 = double(t) .* ((x+y)/2+64) + x + y;
  t3 = uint8(255 & mat2gray(t2));
  imshow(t3);
  