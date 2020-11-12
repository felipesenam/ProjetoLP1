#pragma once

#include <cstdlib>

#ifdef ebug
#define Debug(x) std::cout << x
#else
#define Debug(x)
#endif

#ifdef WIN32
#define CLS system("cls")
#define PAUSE system("pause")
#else
#define CLS system("clear")
#define PAUSE system("read -n1 -p \"Pressione qualquer tecla para continuar. . .\"")
#endif

