clear all 


h1=1.2; %front axle sensor measurement
h2=1;   %rear axle sensor measurement
h=0;    %numb

theta1 = atan((h1-h2)/(2))    %vehicle pitch angle
theta2 = -atan((0.8+h+1.5*sin(theta1))/(5-1.5*cos(theta1)))-theta1 %beam pitch angle






