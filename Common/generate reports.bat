@echo off

setlocal enabledelayedexpansion
set "folder=%~dp0"
for %%i in ("%folder%\*.c" "%folder%\*.h") do (
    set "fileName=%%~ni"
    set "fileExt=%%~xi"
    echo Processing file: !fileName!!fileExt!
    "C:\Program Files\Cppcheck\cppcheck.exe" --dump "!fileName!!fileExt!"
    python "C:\Program Files\Cppcheck\addons\misra.py" "!fileName!!fileExt!".dump > "!fileName!!fileExt!_report.txt" 2>&1
    echo MISRA report for !fileName!!fileExt! generated. Check report for details.
    del "!fileName!!fileExt!.dump"
)
endlocal
