@echo off

echo Generating video decoder project...
echo.

call Externals\premake\premake5.exe vs2017 --file="%~dp0\premake5.lua"

echo.
echo Complete.
echo.

pause