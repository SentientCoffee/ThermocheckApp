@echo off

echo Generating Thermocheck App project...
echo.

call Externals\premake\premake5.exe vs2019 --file="%~dp0\premake5.lua"

echo.
echo Complete.
echo.

pause