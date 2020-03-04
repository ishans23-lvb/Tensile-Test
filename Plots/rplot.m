clc;close all;clear;
DCXY1=csvread("Output/0-0-XY-1");
DCXY2=csvread("Output/0-0-XY-2");
DCXY3=csvread("Output/0-0-XY-3");
DCZ1=csvread("Output/0-0-Z-1");
%%%
D222XY1=csvread("Output/220-2-XY-1");
D222XY2=csvread("Output/220-2-XY-2");
D222XY3=csvread("Output/220-2-XY-3");
D222Z1=csvread("Output/220-2-Z-1");
D222Z2=csvread("Output/220-2-Z-2");
D222Z3=csvread("Output/220-2-Z-3");

D228XY1=csvread("Output/220-8-XY-1");
D228XY2=csvread("Output/220-8-XY-2");
D228XY3=csvread("Output/220-8-XY-3");
D228Z1=csvread("Output/220-8-Z-1");
D228Z2=csvread("Output/220-8-Z-2");
D228Z3=csvread("Output/220-8-Z-3");
%%%
D262XY1=csvread("Output/260-2-XY-1");
D262XY2=csvread("Output/260-2-XY-2");
D262XY3=csvread("Output/260-2-XY-3");
D262Z1=csvread("Output/260-2-Z-1");
D262Z2=csvread("Output/260-2-Z-2");
D262Z3=csvread("Output/260-2-Z-3");

D268XY1=csvread("Output/260-8-XY-1");
D268XY2=csvread("Output/260-8-XY-2");
D268XY3=csvread("Output/260-8-XY-3");
D268Z1=csvread("Output/260-8-Z-1");
D268Z2=csvread("Output/260-8-Z-2");
D268Z3=csvread("Output/260-8-Z-3");
%%%
D32XY1=csvread("Output/300-2-XY-1");
D32XY2=csvread("Output/300-2-XY-2");
D32XY3=csvread("Output/300-2-XY-3");
D32Z1=csvread("Output/300-2-Z-1");
D32Z2=csvread("Output/300-2-Z-2");
D32Z3=csvread("Output/300-2-Z-3");

D38XY1=csvread("Output/300-8-XY-1");
D38XY2=csvread("Output/300-8-XY-2");
D38XY3=csvread("Output/300-8-XY-3");
D38Z1=csvread("Output/300-8-Z-1");
D38Z2=csvread("Output/300-8-Z-2");
D38Z3=csvread("Output/300-8-Z-3");

figure;
subplot(2,2,1);
plot(DCXY1(:,1),DCXY1(:,2));

