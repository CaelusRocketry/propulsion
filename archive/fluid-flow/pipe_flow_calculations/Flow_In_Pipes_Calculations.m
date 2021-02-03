%---------------------------------------------------------------------------------
%head loss & pressure drop in pipes & reynold number & darcy friction   
%factor & PI-groups & Vmean,Vmax and Q & Length of Entrance Region       
%Hatem Abid ... 3/20/2015
%4/12/2015 sun
%---------------------------------------------------------------------------------

clear;clc;disp('                                            ...............****This Script was written by Hatem****............... ')

column={'Head Losses & Pressure Drop in straight pipes';...
    'Darcy-Weisbach Friction Factor';...
    'Reynold Number';...
    'Buckingham Pi Theorem';...
    'Description of Flow with Figures for Laminar';...
    'Length of Entrance Region'};


Symbols=[1;2;3;4;5;6];

inputs={'D,L,f,density and Velocity';...
    'Re and Relative Roughness';...
    'Density,D,V and Viscosity';...
    'Symbols Of Variables and Dim.Vector Matrix';...
    '{Pa,Pb,R,L and Viscosity';...
    'Reynold No. and Daimeter'};

Outputs={'HL and dp';'f';'Re';'Pi-Groups';'Description of flow';...
    'Le'};

Information={'You can calculate f by Press 2 in the start';...
    'Inside it you can calculate Re and r if you need it';...
    'NA';...
    'Enter the min sum vector elements of Variable first';...
    'You can use other function to determine NA information';...
    'For laminar and Turbelent flows only'};

Start=table(Symbols,'RowNames',column)
inputs_Outputs=table(inputs,Outputs,'RowNames',column)
Informations=table(Information,'RowNames',column)
%------------------------------------------------------------------------------------------,,
n=input('How many things you want to do? ');
for i=1:n
    s=input('What do you want to calculate? ');

    %------------------------------------------------------------------------------------------
    %%
    if s==1              % Head loss and Prssure drop

        type={'water';'olive oil';'mercury';'ethanol';...
            'castor oil';'propanol';'pitch';'motor oil'};

        Visvosity_in_P_at_STP=[8.94e-4;0.081;1.526e-3;1.074e-3;...
            0.985;1.945e-3;2.3e+8;0.065];

        Some_of_Viscosities_At_298k_At_298k=table(Visvosity_in_P_at_STP,'RowNames',type)
        L=input('Enter the length in m           ');
        V=input('Enter velcity in m/s         ');
        D=input('Enter the daimeter in mm   ');
        rho=input('Enter the density in kg/m^3      ');
        e=input('Enter the roughness in mm');
        Re_k=input('Do you know Reynold Number? .... YES=1    ,     NO=2      ');
        %%
        if Re_k==2
            vis=input('Enter the viscosity in kg/(m.s)    ');
            Re=rho*D*10^-3*V/vis;
        else Re=input('Enter Reynold number         ');
        end
        %%
        if Re<=2300;display('---------------------')
            f=64/Re;
            display('---------------------');display('Laminar Fow');display('---------------------')
        elseif Re>2300 & Re<4000
            f=darcy(Re,e/D);
            display('---------------------');display('In Transition Zone');display('---------------------')
        else
            f =darcy(Re,e/D);
            display('---------------------');display('Turbelent Flow');display('---------------------')
        end
        %%
        h=f*(L*10^3/ D)*(V.^2)/(9.81*2);
        dp=rho*h*9.81;
        psi_dp=dp*1.45*10^-4;
        ft_h=h*3.281;
        %-------------------------------------------------------------------------TABLE(1)
        %%
        Values=[rho;V;D;L;Re;h;dp];
        Units=char({'kg/m^3';'m/sec';'mm';'m';'without';'m';'Pa'});
        sa={'density';'velocity';'daimeter';'length';'reynold';'head losses';'pressure drop'};
        Summary=table(Values,Units,'RowNames',sa)
        %%
        if Re>2300
            [x y z]=ellipsoid(0,0,0,D,dp,V,100);
            z(z<0)=0;
            figure(1)
            mesh(x,y,z);xlabel('x1/2..Diameter in m');ylabel('Pressure Drop in Pa');zlabel('Velocity in m/s')
            figure(2)
            x(x<0)=0;
            plot(z,x);ylabel('x1/2..Diameter in m');xlabel('Velocity in m/s')
        end
        %----------------------------------------------------------------------------------

    elseif s==2     %Darcy-Weisbach friction factor

        type={'water';'olive oil';'mercury';'ethanol';...
            'castor oil';'propanol';'pitch';'motor oil'};

        Visvosity_in_P_at_STP=[8.94e-4;0.081;1.526e-3;1.074e-3;...
            0.985;1.945e-3;2.3e+8;0.065];

        Some_of_Viscosities_At_298k=table(Visvosity_in_P_at_STP,'RowNames',type)

        Re_k=input('Do you know Reynold Number? .... YES=1    ,     NO=2      ');
        %%
        if Re_k==2
            D=input('Enter the daimeter in mm   ');
            V=input('Enter velcity in m/s         ');
            rho=input('Enter the density in kg/m^3      ');
            e=input('Enter the roughness in mm');
            vis=input('Enter the viscosity in kg/(m.s)    ');
            Re=rho*D*10^-3*V/vis;
        else Re=input('Enter Reynold number         ');
            e=input('Enter the roughness in mm');
            D=input('Enter the daimeter in mm   ');
        end
        %---------------------------------------------------------------------------------
        %%
        if Re<=2300
            f=64/Re;
        else
            f =darcy(Re,e/D);
        end
        %%

        %-------------------------------------------------------------------------TABLE(2,3)
        if Re_k==2
            Values=[Re;f;e;D;V;rho;vis];
            rows={'Reynold number';'Darcy friction factor';'Roughness';'Diameter';'Velocity';'Density';'Viscosity'};
            Units=char({'without';'without';'mm';'mm';'m/sec';'kg/m^3';'kg/(m.sec)'});
            Sumarry=table(Values,Units,'RowNames',rows)
        else Values=[Re;f;e;D];
            rows={'Reynold number';'Darcy friction factor';'Roughness';'Diameter'};
            Units=char({'without';'without';'mm';'mm'});
            Sumarry=table(Values,Units,'RowNames',rows)
        end

    elseif s==3

        type={'water';'olive oil';'mercury';'ethanol';...
            'castor oil';'propanol';'pitch';'motor oil'};

        Visvosity_in_P_at_STP=[8.94e-4;0.081;1.526e-3;1.074e-3;...
            0.985;1.945e-3;2.3e+8;0.065];

        Some_of_Viscosities_At_298k=table(Visvosity_in_P_at_STP,'RowNames',type)
        %%
        D=input('Enter the daimeter in mm   ');
        V=input('Enter velcity in m/s         ');
        rho=input('Enter the density in kg/m^3      ');
        vis=input('Enter the viscosity in kg/(m.s)    ');
        Re=rho*D*10^-3*V/vis;
        %%
        %-------------------------------------------------------------------------TABLE(4)

        rows={'Reynold number';'Diameter';'Velocity';'Density';'Viscosity'};
        Units=char({'without';'mm';'m/sec';'kg/m^3';'kg/(m.sec)'});
        Values=[Re;D;V;rho;vis];
        Sumarry=table(Values,Units,'RowNames',rows)
    end

    %-----------------------------------------------------------------------------------

    if s==4                          %PI-groups of BUCKINGHAM PI THEOREM

        disp('                                ----------***Buchingham Pi Theorem Solutions By Hatem***----------                    ')
        disp('--------------------------------------------------------------------------------------------------------------------------------------------------')
        n=input('How many variables in the problem?');
        disp('----------------------------------------------------------------------------------------------------')
        sym=input('Enter the symbols in cell form');
        %%
        for i=1:n
            disp(' Enter the dimension,in FORM [L M t T], of :'),sym{i}
            Dimension=input( 'Dimension:');
            A(i,:)=Dimension;disp('------------------------------------------------------------------------------------')
        end
        EXPONENINTS_PI_GROUPS=null(A','r');
        
        %%
        %-------------------------------------------------------------------------TABLE(5)

        SOLUTION=table(EXPONENINTS_PI_GROUPS,'RowNames',sym)
    end

    %----------------------------------------------------------------------------------
    if s==5         %Vmean,Vmax and Q

        type={'water';'olive oil';'mercury';'ethanol';...
            'castor oil';'propanol';'pitch';'motor oil'};

        Visvosity_in_P_at_STP=[8.94e-4;0.081;1.526e-3;1.074e-3;...
            0.985;1.945e-3;2.3e+8;0.065];

        Some_of_Viscosities_At_298k=table(Visvosity_in_P_at_STP,'RowNames',type)
        %%
        dbstop if error      %HATEM:original idea by yosif k
        Pa=input('Pressure at point a in Pa    ');
        Pb=input('Pressure at point b in Pb   ');
        mu=input('Viscosity of liquid in kg/m.s   ');
        R=input('Radius of pipe in m   ');
        l=input('Length of pipe in m   ');

        %-------------------------------------------------------------------------TABLE(6)

        Value=[Pa;Pb;mu;R;l];
        Units=char({'Pa';'Pa';'P';'m';'m'});
        Information=table(Value,Units,'RowNames',{'Pa';'Pb';'Viscosity';'Radius';'Length'})

        %---------------------------------------------------------------------------------

        %%
        if  Pa==Pb
            disp('There is No Pressure Drop in the Pipe')
        else

            N=100;
            r=linspace(-R,R,N);
            S= 3.14159285620823*R^2;
            Vmax=(abs(Pa-Pb))*(R^2)/(4*mu*l);
            Vmean=Vmax/2;
            V=Vmax*(1-(r.^2)/R^2);
            Q=Vmean*S;
            %%
            %-------------------------------------------------------------------------TABLE(7)

            Value=[Vmax;Vmean;Q];
            Units=char({'m/sec';'m/sec';'m^3/sec'});
            Sumarry=table(Value,Units,'RowNames',{'Vmax';'Vmean';'Q'})
            [X,Y,Z]=ellipsoid(0,0,0,R,R,Vmax,N);
            Z(Z<0)=0;

            %%
            %---------------------------------------------------------------------------------

            figure(1),
            stem(V,r,'r');
            grid on
            xlabel(' Velocity (m/s)'), ylabel(' Radius (m)'), title(' Velocity profile');

            %%
            %----------------------------------------------------------------------------------

            figure(2)
            contourf(X,Y,Z),
            colormap copper,
            colorbar,
            grid on,
            xlabel('D-X(m)');
            ylabel('D-Y(m)');
            title(' Velocity Profile (m/s),Equipotential layers');
            %%
            %------------------------------------------------------------------------------------
            figure(3)
            meshc(Z,Y,X)
            title('3-D of flow'),
            zlabel('Diameter in m'),ylabel('Diameter in m'),xlabel('Velocity in m/s')

            %%
            %-------------------------------------------------------------------------------------

            figure(5)
            ribbon(r,V)
            ylabel('Diameter in m'),zlabel('Velocity in m/s'),...
                xlabel('strip:uniform width using X = 1:size(Y,1)')

            %%
            %--------------------------------------------------------------------------------------
            wat=input('Do you want to watch how?! .... [y/n]=[1/2]');
            if wat==1
                disp('print:  comet(V,r)')
            end;end;end

    if s==6
        Re_k=input('Do you know Reynold Number? .... YES=1    ,     NO=2      ');
        if Re_k==2
            V=input('Enter velcity in m/s         ');
            rho=input('Enter the density in kg/m^3');
            D=input('Enter the daimeter in mm   ');
            vis=input('Enter the viscosity in kg/(m.s)    ');
            Re=rho*D*10^-3*V/vis;
        else Re=input('Enter Reynold number   ');
            D=input('Enter the daimeter in mm   ');

        end
        %%
        [Le]=Len(Re,D)
        %%
        if Re>4000
            A=Le/(4.4*Re^(1/6));
            ezplot(abs(4.4*Re^(1/6)*D),[0 A 0 Le]);title('D Vs Le')
            grid minor

        elseif Re<2300
            B=Le/(.06*Re);
            syms D
            ezplot(abs(.06*Re*D),[0 B 0 Le]);title('D Vs Le')
            grid minor
        end;
    end
end
