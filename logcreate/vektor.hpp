#pragma once

#include <ostream>

struct Vektor
{
  typedef int MeasureType;
  MeasureType x, y;
};

inline bool operator<(const Vektor& lhs, const Vektor& rhs)
{
  return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}

inline std::ostream& operator<<(std::ostream& out, Vektor v)
  {
  return out << v.x << ' ' << v.y;
}

