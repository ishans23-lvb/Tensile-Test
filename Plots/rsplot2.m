clc;close all;clear;
figure;

subplot(2,2,1)
core_name="0-0";
Data1=csvread("Output2/"+core_name+"-1");
Data2=csvread("Output2/"+core_name+"-2");
Data3=csvread("Output2/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title("Control");
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,2)
core_name="220-2";
Data1=csvread("Output2/"+core_name+"-1");
Data2=csvread("Output2/"+core_name+"-2");
Data3=csvread("Output2/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title("220°C");
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,3)
core_name="260-2";
Data1=csvread("Output2/"+core_name+"-1");
Data2=csvread("Output2/"+core_name+"-2");
Data3=csvread("Output2/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title("260°C");
xlabel("Strain(%)");
ylabel("Stress(GPa)");


subplot(2,2,4)
core_name="300-2";
Data1=csvread("Output2/"+core_name+"-1");
Data2=csvread("Output2/"+core_name+"-2");
Data3=csvread("Output2/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title("300°C");
xlabel("Strain(%)");
ylabel("Stress(GPa)");


sgtitle('3pt Bend Test Results For 2hr XY Samples');