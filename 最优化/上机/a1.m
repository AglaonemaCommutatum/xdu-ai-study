%% 直线
L1=[0,12/5;6,0];
plot(L1(:,1),L1(:,2));hold on
text(2,1,'2x_1+5x_2=12','color','b');

L2=[0,4;8,0];
plot(L2(:,1),L2(:,2));hold on
text(4,2,'x_1+2x_2=8','color','b');

L3=[0,0;0,6];
plot(L3(:,1),L3(:,2));hold on
text(0,0.5,'x_1=0','color','b');

L4=[4,0;4,6];
plot(L4(:,1),L4(:,2));hold on
text(4,1,'x_1=4','color','b');

L5=[0,0;6,0];
plot(L5(:,1),L5(:,2));hold on
text(2.0,0.5,'x_2=0','color','b');

L6=[0,3;6,3];
plot(L6(:,1),L6(:,2));hold on
text(0,3,'x_2=3','color','b');
grid on

%% 填充
[X1,X2]=meshgrid(0:0.01:7,0:0.01:3);
idX1=(2*X1+5*X2>=12)&(X1+2*X2<=8)&(X1>=0)&(X1<=4)&(X2>=0)&(X2<=3);
X1=X1(idX1);
X2=X2(idX1);
k=convhull(X1,X2);
h=fill(X1(k),X2(k),'r');
set(h,'edgealpha',0,'facealpha',0.3)

%% 目标函数
z0=[0,2.4;1.2,0];
plot(z0(:,1),z0(:,2),'k--','LineWidth',1.2);
text(0.5,0.8,'z=2.4');
z1=[0,6.2;3.1,0];
plot(z1(:,1),z1(:,2),'k--','LineWidth',1.2);
text(1,5,'z=6.2');
z2=[0,10;5,0];
plot(z2(:,1),z2(:,2),'g--','LineWidth',1.2);
text(2,6,'z=10');
