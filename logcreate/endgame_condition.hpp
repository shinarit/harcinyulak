#pragma once

#include <memory>

class EndgameCondition
{
public:
  typedef std::unique_ptr<EndgameCondition> ConditionPtr;
  EndgameCondition(ConditionPtr&& nextCondition): m_nextCondition(std::move(nextCondition))
  { }
  bool itIsOver()
  {
    return itIsOverInner() || (m_nextCondition.get() && m_nextCondition->itIsOver());
  }

protected:
  virtual bool itIsOverInner() = 0;

private:
  ConditionPtr m_nextCondition;
};

class TimeoutEngameCondition: public EndgameCondition
{
public:
  TimeoutEngameCondition(int timeLimit, ConditionPtr nextCondition = ConditionPtr()): EndgameCondition(std::move(nextCondition)), m_timeLimit(timeLimit)
  { }

  virtual bool itIsOverInner()
  {
    return m_currTime++ >= m_timeLimit;
  }

private:
  int m_timeLimit;
  int m_currTime = 0;
};
