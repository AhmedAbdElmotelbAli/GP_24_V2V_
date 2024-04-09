@echo off

:loop
set /p fileName="Enter the name of the file to check MISRA (e.g., main.c): "

rem Check if the file exists before proceeding
if not exist "%fileName%" (
    echo File not found. Please enter a valid file name.
    goto loop
)
rem print the report in the screen

"C:\Program Files\Cppcheck\cppcheck.exe" --dump %fileName%
python "C:\Program Files\Cppcheck\addons\misra.py" %fileName%.dump

set /p generateReport="Do you want to generate a MISRA report? (Y/N): "
if /i "%generateReport%"=="Y" (
    python "C:\Program Files\Cppcheck\addons\misra.py" %fileName%.dump  > %fileName%_report.txt
    echo MISRA report generated. Check report for details.
)

del %fileName%.dump

set /p continue="Do you want to check another file? (Y/N): "
if /i "%continue%"=="Y" (
    goto loop
) else if /i "%continue%"=="N" (
    echo Exiting script.
    exit
) else (
    echo Invalid input. Please enter Y or N.
    goto loop
)
