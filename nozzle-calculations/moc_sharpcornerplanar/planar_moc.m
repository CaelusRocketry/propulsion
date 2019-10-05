% Shubham Maurya
% Indian Institute of Space Science and Technology

%{
    This program generates contour for a minimum length nozzle. The flow
    expands through sharp corner at throat. The input parameters are ratio 
    of specific heat, exit design Mach no. and no. of expansion waves
    emanating from sharp corner at throat.    
%}

clear all
clc
tic
%% Gas properties %%
gamma=input('Enter Cp/Cv ');
%% Design parameters %%
Me=input('Enter exit Mach no. : ');
theta_max=PrandtlMeyer(Me,gamma)*180/(2*pi);
%% Incident expansion wave conditions %%
n=input('Enter number of characteristics lines (greater than 2) emanating from sharp corner throat : ');
theta_0=theta_max/n ;
%% Characteristic parameter solver
% v - Prandtl-Meyer function
% KL - Left running characteristic constant
% KR - Right running characteristic constant
% theta - Flow angle relative to horizontal
[v,KL,KR,theta]=moc2d(theta_max,theta_0,n);
%% Mach number and Mach angle at each node
node=0.5*n*(4+n-1);
M=zeros(1,node);
mu=zeros(1,node);
for i=1:node
    M(i)=InvPrandtlMeyer(v(i));
    mu(i)=Mu(M(i));
end
%% Grid generator
figure(1)
D=1; % Non-Dimensional y co-ordinate of throat wall
i=1;
x=zeros(1,node);
y=zeros(1,node);
wall=theta_max;
while (i<=n+1)
    if i==1
        x(i)=-D/(tand(theta(i)-mu(i)));
        y(i)=0;
        plot([0 x(i)],[D 0]);
        hold on
    else if i==n+1
            x(i)=(y(i-1)-D-x(i-1)*tand((theta(i-1)+theta(i)+mu(i-1)+mu(i))*0.5))/(tand(0.5*(wall+theta(i)))-tand((theta(i-1)+theta(i)+mu(i-1)+mu(i))*0.5));
            y(i)=D+x(i)*tand(0.5*(wall+theta(i)));
            plot([x(i-1) x(i)],[y(i-1) y(i)]);
            hold on
            plot([0 x(i)],[D y(i)]);
            hold on
        else
            x(i)=(D-y(i-1)+x(i-1)*tand(0.5*(mu(i-1)+theta(i-1)+mu(i)+theta(i))))/(tand(0.5*(mu(i-1)+theta(i-1)+mu(i)+theta(i)))-tand(theta(i)-mu(i)));
            y(i)=tand(theta(i)-mu(i))*x(i)+D;
            plot([x(i-1) x(i)],[y(i-1) y(i)]);
            hold on
            plot([0 x(i)],[D y(i)]);
            hold  on
        end
    end
    i=i+1;
    hold on
end
h=i;
k=0;
i=h;
for j=1:n-1
    while (i<=h+n-k-1)
        if (i==h)
            x(i)=x(i-n+k)-y(i-n+k)/(tand(0.5*(theta(i-n+k)+theta(i)-mu(i-n+k)-mu(i))));
            y(i)=0;
            plot([x(i-n+k) x(i)],[y(i-n+k) y(i)]);
            hold on
        else if (i==h+n-k-1)
                x(i)=(x(i-n+k)*tand(0.5*(theta(i-n+k)+theta(i)))-y(i-n+k)+y(i-1)-x(i-1)*tand((theta(i-1)+theta(i)+mu(i-1)+mu(i))*0.5))/(tand(0.5*(theta(i-n+k)+theta(i)))-tand((theta(i-1)+theta(i)+mu(i-1)+mu(i))*0.5));
                y(i)=y(i-n+k)+(x(i)-x(i-n+k))*tand(0.5*(theta(i-n+k)+theta(i)));
                plot([x(i-1) x(i)],[y(i-1) y(i)]);
                hold on
                plot([x(i-n+k) x(i)],[y(i-n+k) y(i)]);
                hold on
            else
                s1= tand(0.5*(theta(i)+theta(i-1)+mu(i)+mu(i-1)));
                s2= tand(0.5*(theta(i)+theta(i-n+k)-mu(i)-mu(i-n+k)));
                x(i)=(y(i-n+k)-y(i-1)+s1*x(i-1)-s2*x(i-n+k))/(s1-s2);
                y(i)=y(i-1)+(x(i)-x(i-1))*s1;
                plot([x(i-1) x(i)],[y(i-1) y(i)]);
                hold on
                plot([x(i-n+k) x(i)],[y(i-n+k) y(i)]);
                hold on
            end
        end
        i=i+1;
    end
    k=k+1;
    h=i;
    i=h;
    hold on
end
title(sprintf('Characteristic lines for Mach=%d and Cp/Cv=%d',Me,gamma))
xlabel('x/x0');
ylabel('y/y0');
axis equal
xlim([0 x(node)+0.5])
ylim([0 y(node)+0.5])
toc