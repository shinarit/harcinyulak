#pragma once

#include "vektor.hpp"
#include "bunny.hpp"
#include "command.hpp"

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
  struct BunnyState
  {
    BunnyState(const Bunny& bunny): myBunny(bunny)
    { }
    struct BunnyOutsideWrapper
    {
    public:
      BunnyOutsideWrapper(const Bunny& bunny): bunny(bunny)
      { }
      Vektor position() const
      {
        return bunny.position();
      }
      Vektor direction() const
      {
        return bunny.direction();
      }

    private:
      const Bunny& bunny;
    };
    const Bunny& myBunny;
  };

  typedef std::vector<Bush> BushList;
  typedef std::vector<Bunny> BunnyList;
  typedef std::vector<BunnyState> StateList;

  Map(Vektor size, int bushSize, int bunnyNum, int bunnySize, std::ostream& out);

  void spawnBunny(int bunnyIndex);
  StateList getBunnyStates() const;
  void executeCommands(const CommandList&);

private:
  void logMap();
  void logBunny(int bunnyIndex);
  void logBunnyMove(int bunnyIndex);
  void generateBushes(int num);

  void moveBunnies(const CommandList& commands);

  bool circleHaveNoIntersection(Vektor center, int radius);

  Vektor        m_size;
  int           m_bushSize;
  int           m_bunnySize;
  std::ostream& m_out;

  BushList      m_bushes;
  BunnyList     m_bunnies;
};
