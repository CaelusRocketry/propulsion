figure;
count = 1;
x=[];
x2=[];
y=[];
for i=.125:.01:.6
    x(count)=i;
    y(count)=getDataDiam(i);
    x2(count)=i*25.4;
    count=count+1;
end
disp(x);
disp(y);
plot(x,y);

title('Effect of Pipe Diameter on Pressure Loss');
xlabel('Pipe Diameter (in)');
ylabel('Pressure Drop (mPa)');
disp(x2);
% ax=gca;
% 
% ax_pos = ax.Position; % position of first axes
% ax2 = axes('Position',ax_pos, 'XAxisLocation','top')
% 
% x2 = 3.175:1:50.8;

figure;
count = 1;
x3=[];
x4=[];
y3=[];
for i=1:1:40
    x3(count)=i;
    y3(count)=getDataRough(i);
    x4(count)=i;
    count=count+1;
end
disp(x3);
disp(y3);
plot(x3,y3);

title('Effect of Pipe Roughness on Pressure Loss');
x3label('Pipe Roughness (microm)');
y3label('Pressure Drop (mPa)');

function data = getDataDiam(diameter)
    mdot= 0.9133;
    density= 786;
    visco = 0.00196;
    length = 8;
    diam = diameter*2.54;
    rough = .0000015;
    g = 9.8;
    
    Q = mdot/density;
    V = Q/(pi*(diam/2)^2);
    kvisc = visco/density;
    red = V*diam/kvisc;
    
    f = (1/(-1.8*log10((6.9/red)+((rough/diam)/3.7)^1.11)))^2;
    hf = f*(length/diam)*(V^2/(2*g));
    dP = hf*density*g;
    data = dP/1000000;
end

function data2 = getDataRough(roughness)
    mdot= 0.9133;
    density= 786;
    visco = 0.00196;
    length = 8;
    diam = 0.0127;
    g = 9.8;
    
    rough = roughness / 10^-6;
    
    Q = mdot/density;
    V = Q/(pi*(diam/2)^2);
    kvisc = visco/density;
    red = V*diam/kvisc;
    
    f = (1/(-1.8*log10((6.9/red)+((rough/diam)/3.7)^1.11)))^2;
    hf = f*(length/diam)*(V^2/(2*g));
    dP = hf*density*g;
    data2 = dP/1000000;
end