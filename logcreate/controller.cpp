#include "controller.hpp"
#include "time.hpp"

const Controller::Interval Controller::THINKING_LIMIT(200);

Controller::Command Controller::decideCommand(const Map::BunnyState& state)
{
  if (!m_currentlyRunning)
  {
    m_currentRun = Decider(std::async(std::bind(&Controller::decideCommandInner, this, state)));
  }
  else
  {
  }

  Command command;
  if (m_currentRun.wait_for(THINKING_LIMIT) == std::future_status::timeout)
  {
    m_decisionTimouted = true;
    command.type = Command::CommandType::SUICIDE;
  }
  else
  {
    if (m_decisionTimouted)
    command = m_currentRun.get();
  }

  return command;
}

Controller::Controller()
{
}
