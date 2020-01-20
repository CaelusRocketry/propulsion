%% Optimum Propellant Properties
% Ethanol (75%), H20(25%), GOX
% Jason Chen, Project Caelus, 16 December, 2019

clc; close all;
data = readtable('ethanol-75-lox.csv');
[dims, num_mr] = getNumMixtureRatios(data);

%% Chamber Pressure v. C* v. Mixture Ratio
figure;
ax = gca;
current_mr = data{1,1};
x = zeros(1,dims);
y = zeros(1,dims);
for i=0:size(data,1)-1
    temp_mr = data{i+1,1};
    if temp_mr ~= current_mr
        plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
        hold on;
        current_mr = temp_mr;
    end
    x(mod(i, dims)+1) = data{i+1,2}; 
    y(mod(i, dims)+1) = data{i+1,7}; 
end
plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
hold off;
% yyaxis left;
lgd = legend('show', 'Location', 'southeast');
lgd.Title.String = 'Mixture Ratios';
grid on;
xlabel("Chamber Pressure (Bar)");
ylabel("Theoretical C* (m/sec)");
title({"{\bf\fontsize{14} Chamber Pressure v. C* (Equilibrium)}" ...
    '\fontsize{10} 75% C_{2}H_{5}OH + 25% H_{2}O/Gaseous O_{2} at 5km'}, ...
    'FontWeight', 'Normal');
saveas(gcf, 'cp_cstar_mix.fig'); % gcf = current figure

%% Chamber Pressure v. Combustion Temperature v. Mixture Ratio
figure;
ax = gca;
current_mr = data{1,1};
x = zeros(1,dims);
y = zeros(1,dims);
for i=0:size(data,1)-1
    temp_mr = data{i+1,1};
    if temp_mr ~= current_mr
        plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
        hold on;
        current_mr = temp_mr;
    end
    x(mod(i, dims)+1) = data{i+1,2}; 
    y(mod(i, dims)+1) = data{i+1,4}; 
end
plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
hold off;
% yyaxis left;
lgd = legend('show', 'Location', 'southeast');
lgd.Title.String = 'Mixture Ratios';
grid on;
xlabel("Chamber Pressure (Bar)");
ylabel("Combustion Temperature (K)");
title({"{\bf\fontsize{14} Chamber Pressure v. Temperature (Equilibrium)}" ...
    '\fontsize{10} 75% C_{2}H_{5}OH + 25% H_{2}O/Gaseous O_{2} at 5km'}, ...
    'FontWeight', 'Normal');
saveas(gcf, 'cp_temp_mix.fig');

%% Chamber Pressure v. Molar Weight v. Mixture Ratio
figure;
ax = gca;
current_mr = data{1,1};
x = zeros(1,dims);
y = zeros(1,dims);
for i=0:size(data,1)-1
    temp_mr = data{i+1,1};
    if temp_mr ~= current_mr
        plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
        hold on;
        current_mr = temp_mr;
    end
    x(mod(i, dims)+1) = data{i+1,2}; 
    y(mod(i, dims)+1) = data{i+1,5}; 
end
plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
hold off;
% yyaxis left;
lgd = legend('show', 'Location', 'southeast');
lgd.Title.String = 'Mixture Ratios';
grid on;
xlabel("Chamber Pressure (Bar)");
ylabel("Exhaust Molecular Weight (kg/mol)");
title({"{\bf\fontsize{14} Chamber Pressure v. Molar Weight (Equilibrium)}" ...
    '\fontsize{10} 75% C_{2}H_{5}OH + 25% H_{2}O/Gaseous O_{2} at 5km'}, ...
    'FontWeight', 'Normal');
saveas(gcf, 'cp_molar_mix.fig');

%% Chamber Pressure v. Specific Heat Ratio v. Mixture Ratio
figure;
ax = gca;
current_mr = data{1,1};
x = zeros(1,dims);
y = zeros(1,dims);
for i=0:size(data,1)-1
    temp_mr = data{i+1,1};
    if temp_mr ~= current_mr
        plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
        hold on;
        current_mr = temp_mr;
    end
    x(mod(i, dims)+1) = data{i+1,2}; 
    y(mod(i, dims)+1) = data{i+1,6}; 
end
plot(x, y, 'DisplayName', sprintf('%.2f', current_mr));
hold off;
% yyaxis left;
lgd = legend('show', 'Location', 'southeast');
lgd.Title.String = 'Mixture Ratios';
grid on;
xlabel("Chamber Pressure (Bar)");
ylabel("Ratio of Specific Heats");
title({"{\bf\fontsize{14} Chamber Pressure v. Specific Heat Ratio (Equilibrium)}" ...
    '\fontsize{10} 75% C_{2}H_{5}OH + 25% H_{2}O/Gaseous O_{2} at 5km'}, ...
    'FontWeight', 'Normal');
saveas(gcf, 'cp_gamma_mix.fig');

%% Functions
function [dims, num_mr] = getNumMixtureRatios(data)
temp_mr = data{1,1};
dims = 0;
for i=1:size(data,1)
    if temp_mr ~= data{i,1}
        break
    end
    dims = dims+1;
end
num_mr = size(data,1)/dims;
end