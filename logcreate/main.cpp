#include <getopt.h>

#include "vektor.hpp"
#include "bunny.hpp"
#include "map.hpp"

#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>

struct Options
{
  int bunnySize = 50;
  int bushSize = 100;
  Vektor mapSize = {1000, 1000};
  std::string logFile = "-";
};

bool parseCommandLine(int argc, char* argv[], Options& options);
void runGame(const Options& options);

int main(int argc, char* argv[])
{
  Options options;

  if (parseCommandLine(argc, argv, options))
  {
    runGame(options);
  }
}

option OPTION_BUNNY_SIZE  = {"bunny_size", required_argument, 0, 'b'};
option OPTION_MAP_SIZE    = {"map_size", required_argument, 0, 's'};
option OPTION_LOGFILE     = {"logfile", required_argument, 0, 'l'};

bool parseCommandLine(int argc, char* argv[], Options& options)
{
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
  return true;
}

struct DeleteIfNotStdOut
{
  void operator()(std::ostream* stream)
  {
    if (&std::cout != stream)
    {
      delete stream;
    }
  }
};

void runGame(const Options& options)
{
  std::unique_ptr<std::ostream, DeleteIfNotStdOut> logStream;
  if ("-" == options.logFile)
  {
    logStream.reset(&std::cout);
  }
  else
  {
    logStream.reset(new std::ofstream(options.logFile.c_str()));
  }

  Map map(options.mapSize, options.bushSize, 5);
  bool goalReached(false);
  while (!goalReached)
  {
    /*
    map.spawnBunnies();
    auto stats(map.getStatuses());
    map.moveBunnies();
    map.shootGuns();
    map.moveBullets();
    map.killBunnies();
    */
  }
}
