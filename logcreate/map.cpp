#include "map.hpp"
#include "controller.hpp"

#include <cstdlib>
#include <iterator>

Map::Map(Vektor size, int bushSize, int bunnyNum, int bunnySize, std::ostream& out): m_size(size), m_bushSize(bushSize), m_bunnySize(bunnySize), m_out(out), m_bunnies(bunnyNum)
{
  generateBushes(5);
  for (int i(0); i < m_bunnies.size(); ++i)
  {
    spawnBunny(i);
  }
  logMap();
}

void Map::spawnBunny(int bunnyIndex)
{
  Vektor pos{std::rand() % m_size.x, std::rand() % m_size.y};
  while (circleHaveNoIntersection(pos, m_bunnySize))
  {
    pos = Vektor{std::rand() % m_size.x, std::rand() % m_size.y};
  }
  m_bunnies[bunnyIndex].spawn(pos, Vektor{0, 0});
  logBunny(bunnyIndex);
}

Map::StateList Map::getBunnyStates() const
{
  StateList res;
  for (const auto& bunny : m_bunnies)
  {
    res.push_back(BunnyState{ bunny });
  }
  return res;
}

void Map::executeCommands(const CommandList& commands)
{

  moveBunnies(commands);
/*  map.shootGuns();
  map.moveBullets();
  map.killBunnies();*/
}

void Map::logMap()
{
  m_out << "map: " << m_size << ' ';
  for (Bush& bush: m_bushes)
  {
    m_out << bush.center << ' ' << bush.size << ' ';
  }
  m_out << '\n';
}

void Map::logBunny(int bunnyIndex)
{
  Bunny& bunny(m_bunnies[bunnyIndex]);
  m_out << "bunny: " << bunnyIndex << ' ' << bunny.position() << ' ' << bunny.direction() << '\n';
}

void Map::logBunnyMove(int bunnyIndex)
{
  m_out << "bunnyM: " << bunnyIndex << ' ' << m_bunnies[bunnyIndex].position() << '\n';
}

void Map::generateBushes(int num)
{
  for (int i(0); i < num; ++i)
  {
    Bush bush{{std::rand() % m_size.x, std::rand() % m_size.y}, m_bushSize};
    m_bushes.push_back(bush);
  }
}

void Map::moveBunnies(const CommandList& commands)
{
  for (int i(0); i < commands.size(); ++i)
  {
    auto& command(commands[i]);
    if (Command::CommandType::MOVE == command.type ||
        Command::CommandType::MOVE_AND_SHOOT == command.type)
    {
      auto& bunny(m_bunnies[i]);
      bunny.move(command.move);
      logBunnyMove(i);
    }
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

