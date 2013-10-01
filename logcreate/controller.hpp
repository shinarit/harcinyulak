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
  Controller(Bunny* myBunny);

  const Bunny* bunny()
  {
    return m_myBunny;
  }

private:
  typedef std::chrono::milliseconds Interval;

  static const Interval THINKING_LIMIT;

  typedef std::future<Command> Decider;
  //typedef std::function<Command()>
  Decider*  m_currentRun;
  Bunny*    m_myBunny;
};
