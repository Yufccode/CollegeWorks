clc,clear;
syms x1 x2 s; %�������ű���
f1 =2*x1^2+4*x2^2-6*x1-2*x1*x2;%�趨Ŀ�꺯��
[k f1 f2 f3]=grad(f1,x1,x2,s,[0,1],10^(-5));  %�趨��ʼ��[x1 x2]=[-2.5,4.25]�;���10^(-2)
[result]=sprintf('�� %d �ε����������Сֵ\n',k);%�ڵ������ٴ�֮�������Сֵ
disp(result);
figure(1)
plot(1:k,f3)
title('��������')
xlabel('��������')
ylabel('��Сֵ')
figure(2)
plot3(f1,f2,f3)
hold on
syms x1 x2
f=2*x1^2+4*x2^2-6*x1-2*x1*x2;
fmesh(f)


