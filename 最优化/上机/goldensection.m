%%
function goldensection
g=@(x)x^3-x*4-1;%g（x）
i=0;%初始迭代次数
a=0;
b=3;
k=b-a;
x1=a+0.382*(b-a);
x2=a+0.618*(b-a);%第一次区间缩短计算
while abs(k)>0.001%迭代
    i=i+1;
    y1=g(x1);
    y2=g(x2);
        if y1<y2
            b=x2;
            x2=x1;
            y2=y1;
            x1=a+0.382*(b-a);
            y1=g(x1);
        else
            a=x1;
            x1=x2;
            y1=y2;
            x2=a+0.618*(b-a);
            y2=g(x2);
        end
        k=b-a;
end
x0=(a+b)/2;%求出最后的x
y0=g(x0);%计算最后的y值
%y=g(x);
fplot(g,[0.0,3.0])
hold on;
plot(x0,y0,'r*');
fprintf('%f %f\n',x0,y0);
fprintf('%d',i);

%%

