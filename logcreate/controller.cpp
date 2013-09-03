#include "controller.hpp"
#include "time.hpp"

const Time Controller::thinkingLimit = 0.2;

Controller::Command Controller::decideCommand()
{
  Time start(currentTime());
  Command command(decideCommandInner());
  if (start - currentTime() > thinkingLimit)
  {
    command.type = Command::CommandType::SUICIDE;
  }
  return command;
}

Controller::Controller(Bunny* myBunny): m_myBunny(myBunny)
{
}
