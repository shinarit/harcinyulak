#include "bunny.hpp"

Bunny::Bunny(): m_alive(false)
{
}

void Bunny::spawn(Vektor position, Vektor direction)
{
  m_position = position;
  m_direction = direction;
  m_alive = true;
}
