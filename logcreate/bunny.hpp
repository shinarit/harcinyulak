#pragma once

#include "vektor.hpp"

class Bunny
{
public:
  Bunny();

  void spawn(Vektor position, Vektor direction);

private:
  Vektor  m_position;
  Vektor  m_direction;

  bool    m_alive;
};
