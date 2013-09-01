#pragma once

#include <ctime>

typedef double Time;

inline Time currentTime()
{
  return Time(std::clock())/CLOCKS_PER_SEC;
}
