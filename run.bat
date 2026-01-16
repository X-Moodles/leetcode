@echo off
if not exist launcher.exe (
    echo [Setup] Compiling launcher...
    g++ -std=c++17 launcher.cpp -o launcher.exe
)
launcher.exe %*
