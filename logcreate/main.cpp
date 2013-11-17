#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <vector>

#include "commandline_options.hpp"
#include "vektor.hpp"
#include "bunny.hpp"
#include "map.hpp"
#include "custom_init.hpp"
#include "endgame_condition.hpp"
#include "command.hpp"

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

void printCommands(const CommandList& commands, std::ostream& out)
{
  for (const auto& command : commands)
  {
    out << "command: " << int(command.type);
    switch (command.type)
    {
      case Command::CommandType::SUICIDE:
      {
        break;
      }
      case Command::CommandType::MOVE:
      {
        out << command.move;
      }
      case Command::CommandType::SHOOT:
      {
        out << command.shot;
      }
      case Command::CommandType::MOVE_AND_SHOOT:
      {
        out << command.move << ' ' << command.shot;
      }
    }
    out << '\n';
  }
}

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
    CommandList issuedCommands;
    for (int i(0); i < stats.size(); ++i)
    {
      issuedCommands.push_back(controllers[i]->decideCommand(stats[i]));
    }
    printCommands(issuedCommands, *logStream);

    map.executeCommands(issuedCommands);
  }
}
