@echo off

:loop
set /p fileName="Enter the name of the file to check misra (e.g., main.c): "

"C:\Program Files\Cppcheck\cppcheck.exe" --dump %fileName%
python "C:\Program Files\Cppcheck\addons\misra.py" %fileName%.dump

del %fileName%.dump

goto loop
