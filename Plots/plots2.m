close all;clear all;clc;


core_name="0-0-1";
strain_file="FTEX-Data/"+core_name+".csv";
stress_file="FTLC-Data/"+core_name+".csv";
output_file="Output2/"+core_name;%temp-time-direction-number.csv: xy=0,z=1

VET=readtable(strain_file);
VED=table2array(VET);
LCT=readtable(stress_file);
LCT=LCT(:,3:width(LCT));
LCD=table2array(LCT);



%figure;
%plot(VED(:,1),VED(:,2))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Removing Invalids
i=0;
nivc=0;ivc=0;
si=0;ei=0;

for i=1:size(VED,1)
    if(VED(i,2)>-2e+9)
        nivc=nivc+1;
    else
        nivc=0;
    end
    
    if(nivc>=100)
        si=i-(nivc-1);
        break
    end
end


assert(VED(si,2)>-2e+9 && VED(si-1,2)==-2e+9)

for i=si:size(VED,1)
    if(VED(i,2)==-2e+9)
        ivc=ivc+1;
    else
        ivc=0;
    end
    
    if(ivc>=20)
        ei=i-(ivc);
        break
    end
end

assert(VED(ei,2)>0 && VED(ei+1,2)==-2e+9)


VED=VED(si:ei,:);

figure;
plot(VED(:,1),VED(:,2))
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Align and Strip
close all;
dlen=0;


if(size(VED,1)>=size(LCD,1))
    dlen=size(VED,1)-size(LCD,1);
    TTD(:,1)=VED(dlen+1:size(VED,1),2);
    TTD(:,2)=LCD(:,2);
else
    assert(size(LCD,1)>size(VED,1));
    dlen=size(LCD,1)-size(VED,1);
    TTD(:,1)=VED(:,2);
    TTD(:,2)=LCD(dlen+1:size(LCD,1),2);
end

assert(dlen>=0)
assert(size(TTD,1)==size(VED,1) || size(TTD,1)==size(LCD,1))
assert(size(TTD,1)<=size(VED,1) && size(TTD,1)<=size(LCD,1))
%TTD=[VED(dlen+1:size(VED,1),2)/100,LCD(:,2)];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Clean Up
BTTD=[];
for i=1:size(TTD,1)
    if(TTD(i,1)>-2e+9)
        BTTD(size(BTTD,1)+1,:)=TTD(i,:);
    end
end

assert(size(BTTD,1)<=size(TTD,1))
TTD=BTTD;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Sort
%STTD=TTD;
% assert(size(STTD,1)>100);
% for lim=size(STTD,1):-1:2
%     for i=1:lim-1
%         if(STTD(i,1)>STTD(i+1,1))
%             Temp=STTD(i,:);
%             STTD(i,:)=STTD(i+1,:);
%             STTD(i+1,:)=Temp;
%         end
%     end
% end
% 
% for i=2:size(STTD,1)
%     assert(STTD(i-1,1)<=STTD(i,1));
% end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% View
figure;
plot(TTD(:,1),TTD(:,2))
title(core_name);
xlabel('Strain(%)');
ylabel('Stress(GPa)');

csvwrite(output_file,TTD);
R=csvread(output_file);

figure;
plot(R(:,1),R(:,2));
title(output_file);
xlabel('Strain(%)');
ylabel('Stress(GPa)');