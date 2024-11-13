@echo off

set SERVER_PATH="%~dp0UARTserver\UARTserver.ino"

REM Компіляція клієнтського додатку з бібліотекою inih
g++ -o Build\main.exe Client\ClientMain.cpp Client\ClientCommunication.cpp external\inih\INIReader.cpp external\inih\ini.c -Iexternal\inih
if %errorlevel% neq 0 (
    echo [ERROR] Compilation of client application failed.
    pause
    exit /b %errorlevel%
)

REM Компіляція Arduino програми через платформу Arduino (IDE або arduino-cli)
arduino-cli compile --fqbn arduino:avr:nano UARTserver\UARTserver.ino
if %errorlevel% neq 0 (
    echo [ERROR] Compilation of Arduino code failed.
    pause
    exit /b %errorlevel%
)

echo [INFO] Uploading server code to Arduino...
arduino-cli upload -p COM5 --fqbn arduino:avr:nano:cpu=atmega328old UARTserver\UARTserver.ino
if %errorlevel% neq 0 (
    echo [ERROR] Failed to upload server code to Arduino.
    pause
    exit /b %errorlevel%
)
echo [INFO] Server code uploaded successfully.