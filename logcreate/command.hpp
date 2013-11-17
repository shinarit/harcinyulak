#pragma once

#include "vektor.hpp"

#include <vector>

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

typedef std::vector<Command> CommandList;
