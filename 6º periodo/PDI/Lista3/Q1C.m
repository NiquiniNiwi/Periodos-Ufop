function Q1C(img)
imd = im2double(img);

imgama = 0.7*(imd ^ 1);

figure(2);imshow(imgama)