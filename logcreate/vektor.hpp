#pragma once

#include <ostream>

struct Vektor
{
  typedef int MeasureType;
  Vektor() { invalidate(); }
  Vektor(MeasureType x, MeasureType y): x(x), y(y) {}
  MeasureType x;
  MeasureType y;

  bool valid() const
  {
    return x == Vektor::INVALID_VALUE || y == Vektor::INVALID_VALUE;
  }

  void invalidate()
  {
    x = Vektor::INVALID_VALUE;
  }

  Vektor& operator+=(const Vektor& v)
  {
    x += v.x;
    y += v.y;
    return *this;
  }

private:
  static const MeasureType INVALID_VALUE = INT_MAX;
};

inline bool operator<(const Vektor& lhs, const Vektor& rhs)
{
  return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}

inline std::ostream& operator<<(std::ostream& out, Vektor v)
{
  return out << v.x << ' ' << v.y;
}

inline int distanceSqr(const Vektor& lhs, const Vektor& rhs)
{
  return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}
