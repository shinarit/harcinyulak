#pragma once

#include <future>
#include <chrono>
#include <vector>

#include "map.hpp"
#include "vektor.hpp"
#include "command.hpp"

class Bunny;

class Controller
{
public:
  Controller(const Controller&) = delete;
  Controller& operator=(const Controller&) = delete;
  virtual ~Controller() {}

  Command decideCommand(const Map::BunnyState& state);

protected:
  virtual Command decideCommandInner(const Map::BunnyState& state) = 0;
  Controller();

private:
  typedef std::chrono::milliseconds Interval;
  typedef std::future<Command> Decider;

  static const Interval THINKING_LIMIT;

  Decider         m_currentRun;
  bool            m_currentlyRunning = false;
  bool            m_decisionTimouted = false;
};
