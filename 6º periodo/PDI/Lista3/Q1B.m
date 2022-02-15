function Q1B(img)
imd = im2double(img);

LowHigh = stretchlim(imd);

imst = 1 ./ (1 + (0.6 ./ imd) .^ 3);

nimg = imadjust(img, [LowHigh], [0.1 0.9]);

figure(1);imshow(nimg);
figure(2);imshow(imst);