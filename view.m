clc;clear all;
core_name="300-2-0-3";
view_file="Output/"+core_name+".csv";
Data=csvread(view_file)

figure;
plot(Data(:,1),Data(:,2));
title(core_name);
xlabel('Strain(%)')
ylabel('Stress(GPa)')