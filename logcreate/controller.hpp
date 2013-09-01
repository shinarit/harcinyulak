#pragma once

#include "vektor.hpp"
#include "time.hpp"

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

  virtual ~Controller() {}

  Command decideCommand();

protected:
  Controller(const Controller&) = delete;
  Controller& operator=(const Controller&) = delete;

  virtual Command decideCommandInner() = 0;
  Controller(Bunny* myBunny);

  const Bunny* bunny()
  {
    return m_myBunny;
  }

private:
  Bunny* m_myBunny;

  static const Time thinkingLimit;
};
