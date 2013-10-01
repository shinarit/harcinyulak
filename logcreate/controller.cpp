#include "controller.hpp"
#include "time.hpp"

const Controller::Interval Controller::THINKING_LIMIT(200);

Controller::Command Controller::decideCommand()
{
  if (!m_currentRun)
  {
    m_currentRun = new Decider(std::async(std::bind(&Controller::decideCommandInner, this)));
  }

  //Time start(currentTime());
  Command command(decideCommandInner());
  /*
  if (start - currentTime() > THINKING_LIMIT)
  {
    command.type = Command::CommandType::SUICIDE;
  }
  */
  return command;
}

Controller::Controller(Bunny* myBunny): m_myBunny(myBunny)
{
}
