/** 
   File: Readme_CEAgui-win.txt
   The CEA GUI Download Readme file for Microsoft Windows:
   ( Win98/ NT4.0 / Win2000 / winXP )
   last update: September 28, 2005,  Minna.M.Chao@nasa.gov  216-433-5197
   http://www.grc.nasa.gov/WWW/CEAWeb/ceaguiDownload-win.htm
**/
                
A) The CEA GUI Download consists of the following files:

1) CEAgui-jar.zip - CEAgui JAR file:
   If you have previously installed CEAgui Package , then update to a NEW 
   version of CEAgui by downloading the newest JAR file (CEAgui.jar). 

2) CEA+Fortran.zip - CEA Fortran Package consists of the Source code, Libraries, and examples files. 
   If the Fortran files(cea2.f, cea.inc, syntax.f, b1b2b3.f) must be 
   recompiled on your local machine, then the Fortran executable files for 
   cea2.f, syntax.f, b1b2b3.f should be renamed as FCEA2.exe, syntax.exe, 
   b1b2b3.exe respectively. It included the CEA related packages - CAP, PAC, MISC.
	
3) CEAexec-win.zip - CEAexec Package consists of the following files:
     b1b2b3.exe, syntax.exe - The executables for CEAgui. 
     FCEA2.exe 	            - The executable for cea2. 
     thermo.lib, trans.lib  - The cea2 Fortran library files     
     ceaguiDownload-win.htm - The web page for download.
     Readme_CEAgui-win.txt  - The file you are reading.
     CEAexec-win.bat   	    - run CEAgui using this Batch File
 
                The batch files must contain the following line:
	                    java -classpath "CEAgui.jar" CEAgui

4) If your local system has NOT installed the Java2 SDK (J2SDK), you must 
   install the Java 2 Runtime Environment(JRE) which consists of Java Virtual 
   Machine, the Java platform core classes, and supporting files. It is the 
   runtime part of the J2SDK. j2re1_4_1_03-windows-i586.exe can be downloaded 
   from "http://java.sun.com/j2se/1.4/" for Java2 SDK from Sun Microsoft Inc.
 
B) The CEAexec Package installaton procedures for Windows:

   1.Create the installation Directory on your local machine (e.g. mkdir C:\CEAexec)
   2.Download all three ZIP files and the executable file into the SAME directory 
   (e.g. cd  C:\CEAexec)
   3.Unzip the Fortran Source Code (CEA+Fortran.zip) and save into the SAME directory.
   4.Unzip the CEA GUI Execution file(CEAexec-win.zip)and save into the SAME directory.
   5.Unzip the CEAgui JAR file (CEAgui-jar.zip) and save into the SAME directory..
   6.Double-click on the file (j2re1_4_1_03-windows-i586) to install 
     Java Runtime Environment(JRE)by using the system DEFAULT directory 
     (e.g. C:\Program Files\Java Soft\JRE\1.4)
   7.Execute the batch file (CEAexec-win.bat) for using the file CEAgui.jar.
     Try examples by selecting "Open Examples" from the "File" Menu and choosing an example. 
     Then select "Run CEA2 Executable" from the "Activity" Menu.	


   