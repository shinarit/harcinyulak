#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>

#include "commandline_options.hpp"
#include "vektor.hpp"
#include "bunny.hpp"
#include "map.hpp"
#include "custom_init.hpp"
#include "endgame_condition.hpp"

void runGame(const Options& options);

int main(int argc, char* argv[])
{
  std::srand(std::time(0));

  Options options;

  if (parseCommandLine(argc, argv, options))
  {
    runGame(options);
  }
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

  ControllerArray controllers(createControllers());
  Map map(options.mapSize, options.bushSize, controllers.size(), options.bunnySize, *logStream);
  EndgameCondition::ConditionPtr endgame(new TimeoutEngameCondition(20));
  while (!endgame->itIsOver())
  {
    std::cout << "E!\n";
    auto stats(map.getBunnyStates());
    /*
    map.moveBunnies();
    map.shootGuns();
    map.moveBullets();
    map.killBunnies();
    */
    break;
  }
}
