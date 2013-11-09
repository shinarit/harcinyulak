#include "commandline_options.hpp"

#ifndef _WIN32
#include <getopt.h>

option OPTION_BUNNY_SIZE = { "bunny_size", required_argument, 0, 'b' };
option OPTION_MAP_SIZE = { "map_size", required_argument, 0, 's' };
option OPTION_LOGFILE = { "logfile", required_argument, 0, 'l' };

#endif

bool parseCommandLine(int argc, char* argv[], Options& options)
{
#ifndef _WIN32
  option longOptions[] = {
    OPTION_BUNNY_SIZE,
    OPTION_MAP_SIZE,
    OPTION_LOGFILE
  };

  int optionIndex;
  int c;
  while (-1 != (c = getopt_long(argc, argv, "s:l:", longOptions, &optionIndex)))
  {
    switch (c)
    {
    case 'b':
    {
          options.bunnySize = std::atoi(optarg);

          break;
    }
    case 's':
    {
          int width;
          int height;
          char c;
          std::istringstream str(optarg);
          str >> width >> c >> height;

          if (str.fail())
          {
            std::cerr << "Invalid argument for --" << OPTION_MAP_SIZE.name << ": " << optarg << ".\n";

            return false;
          }

          options.mapSize.x = width;
          options.mapSize.y = height;

          break;
    }
    case 'l':
    {
          options.logFile = optarg;

          break;
    }
    case '?':
    {
          return false;
    }

    }
  }
#endif
  return true;
}

