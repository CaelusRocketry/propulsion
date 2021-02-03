fid = fopen('black_box_COLDFLOW_pi.txt');
t0=1600021090.6956787
rawData=zeros(1,3629)
filteredData=zeros(1,3629)
timeData=zeros(1,3629)
count=1
while ~feof(fid)
    tline = fgetl(fid);
    data = extractBetween(tline,"[","]")
    time = extractBetween(tline,"timestamp","}")
    if(size(data,1)~=0)
        a=extractNumFromStr(char(data(1,1)))
        rawData(1,count)=a(1,1);
        filteredData(1,count)=a(1,2);
        b=extractNumFromStr(char(time(1,1)))
        timeData(1,count)=b(1,1)-t0;
    end
    count=count+1
end
fclose(fid);
tiledlayout(2,1)
nexttile
isNZ=(~filteredData==0);      
plot(timeData(isNZ),filteredData(isNZ))
title('Filtered Pressure (PT-1) Over Time')
ylabel('Pressure (PSI)')
xlabel('Time (s)')
nexttile
isNZ=(~filteredData==0);      
plot(timeData(isNZ),rawData(isNZ))
title('Pressure (PT-1) Over Time')
ylabel('Pressure (PSI)')
xlabel('Time (s)')
function numArray = extractNumFromStr(str)
str1 = regexprep(str,'[,;=]', ' ');
str2 = regexprep(regexprep(str1,'[^- 0-9.eE(,)/]',''), ' \D* ',' ');
str3 = regexprep(str2, {'\.\s','\E\s','\e\s','\s\E','\s\e'},' ');
numArray = str2num(str3);
end