@echo off
setlocal

rem Verifica se o diretório foi passado como argumento
if "%~1"=="" (
    echo Por favor, forneça o diretório a ser monitorado.
    exit /b 1
)

set "DIR_TO_WATCH=%~1"

rem Verifica se o diretório existe
if not exist "%DIR_TO_WATCH%" (
    echo O diretório %DIR_TO_WATCH% não existe.
    exit /b 1
)

rem Comando para iniciar o servidor Python
set "START_COMMAND=python %DIR_TO_WATCH%\main.py"  rem Substitua pelo comando que inicia sua aplicação

rem Pega a última modificação de qualquer arquivo Python no diretório
for /f "delims=" %%i in ('forfiles /p "%DIR_TO_WATCH%" /m *.py /c "cmd /c echo @fdate @ftime"') do (
    set "LAST_MODIFICATION=%%i"
)

rem Executa o servidor Python pela primeira vez
start "" cmd /c %START_COMMAND%
set "PID=$!"

:loop
rem Aguarda 1 segundo
timeout /t 1 /nobreak >nul

rem Pega a nova modificação
set "NEW_MODIFICATION="
for /f "delims=" %%i in ('forfiles /p "%DIR_TO_WATCH%" /m *.py /c "cmd /c echo @fdate @ftime"') do (
    set "NEW_MODIFICATION=%%i"
)

rem Verifica se houve modificação
if not "%NEW_MODIFICATION%"=="%LAST_MODIFICATION%" (
    echo Arquivos modificados. Reiniciando servidor...
    taskkill /PID %PID% /F >nul 2>&1
    start "" cmd /c %START_COMMAND%
    set "LAST_MODIFICATION=%NEW_MODIFICATION%"
)

goto loop
