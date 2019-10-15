emma1 = imread('emma1.jpg');
emma2 = imread('emma2.jpg');
emma3 = imread('emma3.jpg');
emma4 = imread('emma4.jpg');
emma5 = imread('emma5.jpg');

dogs1 = imread('dogs1.jpg');
dogs2 = imread('dogs2.jpg');
dogs3 = imread('dogs3.jpg');
dogs4 = imread('dogs4.jpg');
dogs5 = imread('dogs5.jpg');

land1 = imread('land1.jpg');
land2 = imread('land2.jpg');
land3 = imread('land3.jpg');
land4 = imread('land4.jpg');
land5 = imread('land5.jpg');

emma1 = rgb2gray(emma1);emma1=double(emma1);
emma2 = rgb2gray(emma2);emma2=double(emma2);
emma3 = rgb2gray(emma3);emma3=double(emma3);
emma4 = rgb2gray(emma4);emma4=double(emma4);
emma5 = rgb2gray(emma5);emma5=double(emma5);

land5 = rgb2gray(land5);land5=double(land5);
land4 = rgb2gray(land4);land4=double(land4);
land3 = rgb2gray(land3);land3=double(land3);
land2 = rgb2gray(land2);land2=double(land2);
land1 = rgb2gray(land1);land1=double(land1);

dogs1 = rgb2gray(dogs1);dogs1=double(dogs1);
dogs2 = rgb2gray(dogs2);dogs2=double(dogs2);
dogs3 = rgb2gray(dogs3);dogs3=double(dogs3);
dogs4 = rgb2gray(dogs4);dogs4=double(dogs4);
dogs5 = rgb2gray(dogs5);dogs5=double(dogs5);

 inputdata = [emma1(1:420,:);emma2(1:420,:);emma3(1:420,:);emma4(1:420,:);emma5(1:420,:)];
target = [ones(2100,1) zeros(2100,1) zeros(2100,1)];

inputdata = [inputdata; dogs1(1:420,:);dogs2(1:420,:);dogs3(1:420,:);dogs4(1:420,:);dogs5(1:420,:);];
target = [target;zeros(2100,1) ones(2100,1) zeros(2100,1)];

inputdata = [inputdata; land1(1:420,:);land2(1:420,:);land3(1:420,:);land4(1:420,:);land5(1:420,:);];
target = [target;zeros(2100,1) zeros(2100,1) ones(2100,1)];
 inputdata = inputdata';
target = target';
