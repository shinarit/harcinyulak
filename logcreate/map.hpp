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

  Map(Vektor size, int bushSize, int bunnyNum, int bunnySize);

  void spawnBunny(int bunnyIndex);

  void logMap(std::ostream& out);

private:
  void generateBushes(int num);

  bool circleHaveNoIntersection(Vektor center, int radius);

  Vektor    m_size;
  int    m_bushSize;
  int    m_bunnySize;

  BushList  m_bushes;
  BunnyList m_bunnies;
};
