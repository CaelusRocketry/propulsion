InitialPressure = rand(4.1, 4.5,'double'); Pressure = InitialPressure;
InitialDiameter = 0.5; Diameter = InitialDiameter;

Kp = 1;
Ki = 0.2;
Kd = 0.2;

dt = 0.01;
time = 10;
n = round(time/dt);

mult = 0.1;
desired = 3;


Prop(1:n+1) = 0; Der(1:n+1) = 0; Int(1:n+1) = 0; I(1:n+1) = 0; Error(1:n+1) = 0; PID(1:n+1) = 0;
PressureArray(1:n+1) = 0; DiameterArray(1:n+1) = 0;

for i=1:n+1
    PressureArray(i) = Pressure;
    DiameterArray(i) = Diameter;
    Error(i+1) = PressureArray(i) - desired; % error entering the PID controller
    
    Prop(i+1) = mult * Error(i+1);% error of proportional term
    Der(i+1)  = (Error(i+1) - Error(i))/dt; % derivative of the error
    Int(i+1)  = (Error(i+1) + Error(i))*dt/2; % integration of the error
    I(i+1)    = sum(Int); % the sum of the integration of the error
   
    temp = Kp*Prop(i+1) + Ki*I(i+1)+ Kd*Der(i+1);
    if temp > 0.2 % the three PID terms
       PID(i+1) = 0.2;
    elseif temp < -0.2
       PID(i+1) = -0.2;
    else
        PID(i+1) = temp;
    end
    
    Diameter = Diameter + temp;
    if Diameter > 0.5
        Diameter = 0.5;
    elseif Diameter < 0
        Diameter = 0;
    end
    
    Pressure = Pressure - pressureDrop(0.6391, 0.0127, 0.1524, 1.429, 20.54 * 10^-6);
    Pressure = Pressure - bernouli(1.429, 5, 69);
    Pressure = Pressure - pressureDrop(0.6391, 0.0127, 0.1524, 1.429, 20.54 * 10^-6);

    
end

plot(1:n+1, PressureArray);
%plot(1:n+1, DiameterArray);
%%
function pressureDrop [Pd] = line(FlowRate, PipeInsideDiameter, PipeLength, Density, DynamicViscosity)
    Pd = (128 * DyanmicViscosity * Length * FlowRate)/(pi * Diameter^4);
end
%%
function bernouli bP = line(Desnity, Velocity1, Velocity2)
    bP = 0.5 * Desnity * (Velocity2^2 - Velocity1^2);
end
