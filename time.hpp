#pragma once

#include <ctime>

typedef double Time;

Time currentTime()
{
  return Time(std::clock())/CLOCKS_PER_SEC;
}

#ifdef __linux__


#elif defined _WIN32


#else

#error "System not recognized, you cant measure time now QQ"

#endif 