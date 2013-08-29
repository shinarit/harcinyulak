#include "controller.hpp"
#include "time.hpp"

Controller::Command Controller::decideCommand()
{
  Time start(currentTime());
  Command command(decideCommandInner());
  if (start - currentTime() > thinkingLimit)
  {
    command.type = CommandType::SUICIDE;
  }
  return command;
}

Controller::Controller(Bunny* myBunny): m_myBunny(myBunny)
{
}
