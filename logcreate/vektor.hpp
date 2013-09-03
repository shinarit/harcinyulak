#pragma once

struct Vektor
{
  typedef int MeasureType;
  MeasureType x, y;
};

inline bool operator<(const Vektor& lhs, const Vektor& rhs)
{
  return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}
