#pragma once

#include <future>
#include <chrono>

#include "vektor.hpp"

class Bunny;

class Controller
{
public:
  struct Command
  {
    enum class CommandType
    {
      SUICIDE,
      MOVE,
      SHOOT,
      MOVE_AND_SHOOT
    };
    typedef Vektor Move;
    typedef Vektor Shot;

    CommandType type;

    Move move;
    Shot shot;
  };

  Controller(const Controller&) = delete;
  Controller& operator=(const Controller&) = delete;
  virtual ~Controller() {}

  Command decideCommand();

protected:
  virtual Command decideCommandInner() = 0;
  Controller();

private:
  typedef std::chrono::milliseconds Interval;
  typedef std::future<Command> Decider;

  static const Interval THINKING_LIMIT;

  Decider         m_currentRun;
  bool            m_currentlyRunning = false;
  bool            m_decisionTimouted = false;
};
