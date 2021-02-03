function [v,KL,KR,theta]=moc2d(theta_max,theta_0,n)
dtheta=(theta_max-theta_0)/(n-1);
%7+1,6+1,5+1,4+1,3+1,2+1,1+1
node=0.5*n*(4+n-1);
theta=zeros(1,node);
v=zeros(1,node);
KL=zeros(1,node);
KR=zeros(1,node);
for i=1:n
    theta(i)=theta_0+(i-1)*dtheta;
    v(i)=theta(i);
    KL(i)=theta(i)-v(i);
    KR(i)=theta(i)+v(i);
end
i=n+1;
theta(i)=theta(i-1);
v(i)=v(i-1);
KL(i)=KL(i-1);
KR(i)=KR(i-1);
p=2;
q=n+2;
for k=1:n-1
    j=p;
    h=q;
    theta(h)=0;
    KR(h)=KR(j);
    v(h)=KR(j)-theta(h);
    KL(h)=theta(h)-v(h);
    j=j+1;
    for i=h+1:n-p+q
        KR(i)=KR(j);
        KL(i)=KL(i-1);
        theta(i)=0.5*(KL(i)+KR(i));
        v(i)=0.5*(KR(i)-KL(i));
        j=j+1;
    end
    if i==n-p+q
        h=i+1;
    else
        h=h+1;
    end
    theta(h)=theta(h-1);
    v(h)=v(h-1);
    KL(h)=KL(h-1);
    KR(h)=KR(h-1);
    p=p+1;
    q=h+1;
end
end