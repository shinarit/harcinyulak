#include "map.hpp"

#include <cstdlib>
#include <ctime>
#include <iterator>

Map::Map(Vektor size, int bushSize, int bunnyNum): m_size(size), m_bushSize(bushSize), m_bunnies(bunnyNum)
{
  generateBushes(5);
}

void Map::generateBushes(int num)
{
  std::srand(std::time(0));
  for (int i(0); i < num; ++i)
  {
    Bush bush{{std::rand() % m_size.x, std::rand() % m_size.y}, m_bushSize};
    m_bushes.push_back(bush);
  }
}

