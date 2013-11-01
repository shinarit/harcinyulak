#include "map.hpp"

#include <cstdlib>
#include <iterator>

Map::Map(Vektor size, int bushSize, int bunnyNum, int bunnySize): m_size(size), m_bushSize(bushSize), m_bunnySize(bunnySize), m_bunnies(bunnyNum)
{
  generateBushes(5);
  for (int i(0); i < m_bunnies.size(); ++i)
  {
    spawnBunny(i);
  }
}

void Map::spawnBunny(int bunnyIndex)
{
  Vektor pos{std::rand() % m_size.x, std::rand() % m_size.y};
  while (circleHaveNoIntersection(pos, m_bunnySize))
  {
    pos = Vektor{std::rand() % m_size.x, std::rand() % m_size.y};
  }
  m_bunnies[bunnyIndex].spawn(pos, Vektor{0, 0});
}

void Map::logMap(std::ostream& out)
{
  out << "map " << m_size << ' ';
  for (Bush& bush: m_bushes)
  {
    out << bush.center << ' ' << bush.size << ' ';
  }
  out << '\n';
}


void Map::generateBushes(int num)
{
  for (int i(0); i < num; ++i)
  {
    Bush bush{{std::rand() % m_size.x, std::rand() % m_size.y}, m_bushSize};
    m_bushes.push_back(bush);
  }
}

bool Map::circleHaveNoIntersection(Vektor center, int radius)
{
  for (auto& bush: m_bushes)
  {
    int threshSqr((bush.size + radius) * (bush.size + radius));
    if (distanceSqr(bush.center, center) <= threshSqr)
    {
      return false;
    }
  }

  for (auto& bunny: m_bunnies)
  {
    if (bunny.alive())
    {
      int threshSqr((m_bunnySize + radius) * (m_bunnySize + radius));
      if (distanceSqr(bunny.position(), center) <= threshSqr)
      {
        return false;
      }
    }
  }
  return true;
}

