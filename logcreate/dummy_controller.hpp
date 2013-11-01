#pragma once

#include "controller.hpp"

class DummyController: public Controller
{
public:
protected:
    virtual Command decideCommandInner()
    {
      return Command{Controller::Command::CommandType::MOVE_AND_SHOOT, {100, 100}, {100, 100}};
    }
private:
};
