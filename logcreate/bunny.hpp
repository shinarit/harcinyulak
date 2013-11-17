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

  void move(const Vektor& speed)
  {
    m_position += speed;
  }

private:
  Vektor  m_position;
  Vektor  m_direction;

  bool    m_alive;
};
