#pragma once

#include "vektor.hpp"

#include <string>

struct Options
{
  int bunnySize = 50;
  int bushSize = 100;
  Vektor mapSize = { 1000, 1000 };
  std::string logFile = "-";
};

bool parseCommandLine(int argc, char* argv[], Options& options);

