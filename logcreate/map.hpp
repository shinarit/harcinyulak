#pragma once

#include "vektor.hpp"
#include "bunny.hpp"

#include <vector>
#include <ostream>

struct Bush
{
  Vektor  center;
  int     size;
};

class Map
{
public:
  typedef std::vector<Bush> BushList;
  typedef std::vector<Bunny> BunnyList;

  Map(Vektor size, int bushSize, int bunnyNum);

  void logMap(std::ostream& out);

private:
  void generateBushes(int num);

  Vektor    m_size;
  int       m_bushSize;

  BushList  m_bushes;
  BunnyList m_bunnies;
};
