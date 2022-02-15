function Q1A(img)
h = imhist(img);

figure(1);plot(h);

nimg = imadjust(img, [100/255 160/255], [0.1 0.9]);

figure(2);imshow(nimg);