#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>

std::string Color(std::string color);

void printTitle(std::string title, std::string cor);
void printMenu(std::string title, std::string subtitle, std::string cor);

void ffBuffer();
bool isany(const char, std::string);

#define RETURNIF(x, y, z) if(x == y){ std::cout << "Operação cancelada pelo usuário." << std::endl; PAUSE; return z;}
#define VOIDRETURN
#define WARN(x) std::cout << Color(fYELLOW) << x << Color(fRESET);

#define BOXWIDTH 60

#ifdef DEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x)
#endif

#ifdef WIN32

#include <windows.h>
#include <direct.h>

#define bRESET         "00"
#define fRESET         "07"

#define fBLACK         "00"
#define fBLUE          "01"
#define fGREEN         "02"
#define fCYAN          "03"
#define fRED           "04"
#define fMAGENTA       "05"
#define fYELLOW        "06"
#define fLIGHT_GRAY    "07"
#define fDARK_GRAY     "08"
#define fLIGHT_BLUE    "09"
#define fLIGHT_GREEN   "10"
#define fLIGHT_CYAN    "11"
#define fLIGHT_RED     "12"
#define fLIGHT_MAGENTA "13"
#define fLIGHT_YELLOW  "14"
#define fWHITE         "15"
#define bBLACK         "16"
#define bBLUE          "17"
#define bGREEN         "18"
#define bCYAN          "19"
#define bRED           "20"
#define bMAGENTA       "21"
#define bYELLOW        "22"
#define bLIGHT_GRAY    "23"
#define bDARK_GRAY     "24"
#define bLIGHT_BLUE    "25"
#define bLIGHT_GREEN   "26"
#define bLIGHT_CYAN    "27"
#define bLIGHT_RED     "28"
#define bLIGHT_MAGENTA "29"
#define bLIGHT_YELLOW  "30"
#define bWHITE         "31"

#define OSENVPART system("chcp 65001 >nul")
#define PAUSE system("pause")

#ifndef NOCLS
#define CLS system("cls")
#else
#define CLS
#endif

#else

#include <termios.h>
#include <unistd.h>

#define fRESET         "\x1b[39m"
#define bRESET         "\x1b[49m"

#define fBLACK         "\x1b[30m"
#define fRED           "\x1b[31m"
#define fGREEN         "\x1b[32m"
#define fYELLOW        "\x1b[33m"
#define fBLUE          "\x1b[34m"
#define fMAGENTA       "\x1b[35m"
#define fCYAN          "\x1b[36m"
#define fLIGHT_GRAY    "\x1b[37m"
#define fDARK_GRAY     "\x1b[90m"
#define fLIGHT_RED     "\x1b[91m"
#define fLIGHT_GREEN   "\x1b[92m"
#define fLIGHT_YELLOW  "\x1b[93m"
#define fLIGHT_BLUE    "\x1b[94m"
#define fLIGHT_MAGENTA "\x1b[95m"
#define fLIGHT_CYAN    "\x1b[96m"
#define fWHITE         "\x1b[97m"
#define bBLACK         "\x1b[40m"
#define bRED           "\x1b[41m"
#define bGREEN         "\x1b[42m"
#define bYELLOW        "\x1b[43m"
#define bBLUE          "\x1b[44m"
#define bMAGENTA       "\x1b[45m"
#define bCYAN          "\x1b[46m"
#define bLIGHT_GRAY    "\x1b[47m"
#define bDARK_GRAY     "\x1b[100m"
#define bLIGHT_RED     "\x1b[101m"
#define bLIGHT_GREEN   "\x1b[102m"
#define bLIGHT_YELLOW  "\x1b[103m"
#define bLIGHT_BLUE    "\x1b[104m"
#define bLIGHT_MAGENTA "\x1b[105m"
#define bLIGHT_CYAN    "\x1b[106m"
#define bWHITE         "\x1b[107m"

#define OSENVPART
#define PAUSE ffBuffer(); std::cout << "Pressione qualquer tecla para continuar. . ." << std::endl; getchar();

#ifndef NOCLS
#define CLS system("clear")
#else
#define CLS
#endif

#endif
