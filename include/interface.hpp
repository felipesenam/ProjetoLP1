#pragma once

#include <iostream>
#include <iomanip>
#include <limits>

#include "animal.hpp"
#include "petfera.hpp"
#include "lib.hpp"

using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;

void run(PetFera pets);

void printTitle(string title, int largura, std::string cor);
void printMenu();