function [ Le ]=Len(Re,D)
if Re<2300
    Le=0.06*Re*D;
elseif Re>=4000
    Le=4.4*Re^(1/6)*D;
else disp('In transition zone,Can not calculate Le')
end
end
