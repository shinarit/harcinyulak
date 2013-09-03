#pragma once

#include "vektor.hpp"

class Bunny
{
public:
  Bunny();

  Vektor position() const;

private:
  Vektor  m_position;

  bool    m_alive;
};
