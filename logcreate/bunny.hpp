#pragma once

#include "vektor.hpp"

class Bunny
{
public:
  Bunny();

  void spawn(Vektor position, Vektor direction);

  bool alive() const
  {
    return m_alive;
  }

  Vektor position() const
  {
    return m_position;
  }
  Vektor direction() const
  {
    return m_direction;
  }

private:
  Vektor  m_position;
  Vektor  m_direction;

  bool    m_alive;
};
