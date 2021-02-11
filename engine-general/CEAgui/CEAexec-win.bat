@ECHO OFF
REM   CEAexec-win.bat  -  Batch file to start the CEA GUI Application (CEAgui) for Windows
REM   http://www.grc.nasa.gov/WWW/CEAWeb/CEAexec-win.bat
REM   05/21/2004          Minna Chao ,  NASA Glenn Research Center.

REM   C:
REM   cd \CEAexec

REM   JAVAHOME=C:\JDK
REM   SET PATH=%PATH%;%JAVAHOME%\BIN
 
REM   The following line assumes that the JDK 1.4 
REM   PATH=C:\WINDOWS;C:\WINDOWS\COMMAND;C:\JDK\BIN;
REM   or at least the
REM   JRE 1.4 has been downloaded to the local PC;
REM   PATH=C:\WINDOWS;C:\WINDOWS\COMMAND;C:\JRE\BIN; 

REM   Check that you have the files in this directory:
REM   CEAgui.jar, thermo.lib, and trans.lib
REM   b1b2b3.exe, syntax.exe, and FCEA2.exe

REM echo java -help
REM java -help

java -version
echo "  "
echo dir CEAgui.jar
dir CEAgui* 

echo dir *.lib
dir *.lib

echo dir *.exe
dir *.exe
echo "---------------------------------------------"
echo  java -classpath  CEAgui.jar  CEAgui
java  -classpath "CEAgui.jar" CEAgui
