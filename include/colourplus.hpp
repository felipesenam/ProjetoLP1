#pragma once

#include <iostream>

#ifdef WIN32
#include <windows.h>
#include <direct.h>
#include <cstdlib>

#define fRESET         textfg(15)
#define fBLACK         textfg(0)
#define fBLUE          textfg(1)
#define fGREEN         textfg(2)
#define fCYAN          textfg(3)
#define fRED           textfg(4)
#define fMAGENTA       textfg(5)
#define fYELLOW        textfg(6)
#define fLIGHT_GRAY    textfg(7)
#define fDARK_GRAY     textfg(8)
#define fLIGHT_BLUE    textfg(9)
#define fLIGHT_GREEN   textfg(10)
#define fLIGHT_CYAN    textfg(11)
#define fLIGHT_RED     textfg(12)
#define fLIGHT_MAGENTA textfg(13)
#define fLIGHT_YELLOW  textfg(14)
#define fWHITE         textfg(15)
#define bRESET         textbg(0)
#define bBLACK         textbg(0)
#define bBLUE          textbg(1)
#define bGREEN         textbg(2)
#define bCYAN          textbg(3)
#define bRED           textbg(4)
#define bMAGENTA       textbg(5)
#define bYELLOW        textbg(6)
#define bLIGHT_GRAY    textbg(7)
#define bDARK_GRAY     textbg(8)
#define bLIGHT_BLUE    textbg(9)
#define bLIGHT_GREEN   textbg(10)
#define bLIGHT_CYAN    textbg(11)
#define bLIGHT_RED     textbg(12)
#define bLIGHT_MAGENTA textbg(13)
#define bLIGHT_YELLOW  textbg(14)
#define bWHITE         textbg(15)

#define OSENVPART system("chcp 65001 >nul")

std::string textfg(int color)
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= color);
	return "";
}

std::string textbg(int color)
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (color << 4));
	return "";
}

#else
#include <termios.h>
#include <unistd.h>

#define fRESET         "\x1b[39m"
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
#define bRESET         "\x1b[49m"
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

#endif
