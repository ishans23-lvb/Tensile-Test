%% Control
clc;close all;clear;
figure;

subplot(1,2,1)
core_name="0-0-XY";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(1,2,2)
core_name="0-0-Z";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

sgtitle('Control');
%% 220
figure;

subplot(2,2,1)
core_name="220-2-XY";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,2)
core_name="220-8-XY";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,3)
core_name="220-2-Z";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,4)
core_name="220-8-Z";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

sgtitle('220°C')
%% 260
figure;

subplot(2,2,1)
core_name="260-2-XY";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,2)
core_name="260-8-XY";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,3)
core_name="260-2-Z";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,4)
core_name="260-8-Z";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

sgtitle('260°C')
%% 300
figure;

subplot(2,2,1)
core_name="300-2-XY";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,2)
core_name="300-8-XY";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,3)
core_name="300-2-Z";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

subplot(2,2,4)
core_name="300-8-Z";
Data1=csvread("Output/"+core_name+"-1");
Data2=csvread("Output/"+core_name+"-2");
Data3=csvread("Output/"+core_name+"-3");
plot(Data1(:,1),Data1(:,2));hold on;
plot(Data2(:,1),Data2(:,2));hold on;
plot(Data3(:,1),Data3(:,2));hold on;
title(core_name);
xlabel("Strain(%)");
ylabel("Stress(GPa)");

sgtitle('300°C')