#pragma once

#include <chrono>
#include <thread>

#include "controller.hpp"

class DummyController: public Controller
{
public:
  //milliseconds to sleep
  DummyController(int thinkingTime): m_thinkingTime(thinkingTime)
  {}
protected:
  virtual Command decideCommandInner(const Map::BunnyState& state)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(m_thinkingTime));
    return Command{Controller::Command::CommandType::MOVE_AND_SHOOT, {100, 100}, {100, 100}};
  }
private:
  int m_thinkingTime;
};
