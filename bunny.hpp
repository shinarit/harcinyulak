#pragma once

#include "vektor.hpp"

class Bunny
{
public:
  Bunny(const Vektor& position);

  Vektor position() const;

private:
  Vektor m_position;
};
