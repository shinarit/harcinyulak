#include "controller.hpp"
#include "time.hpp"

const Controller::Interval Controller::THINKING_LIMIT(200);

Controller::Command Controller::decideCommand()
{
  if (!m_currentlyRunning)
  {
    m_currentRun = Decider(std::async(std::bind(&Controller::decideCommandInner, this)));
  }
  else
  {
  }

  Command command;
  if (m_currentRun.wait_for(THINKING_LIMIT) == std::future_status::timeout)
  {
    m_decideTimouted = true;
    command.type = Command::CommandType::SUICIDE;
  }
  else
  {
    if (m_decideTimouted)
    command = m_currentRun.get();
  }

  return command;
}

Controller::Controller(Bunny* myBunny): m_myBunny(myBunny)
{
}
