#pragma once

#include <vector>
#include <memory>

#include "controller.hpp"

typedef std::vector<std::unique_ptr<Controller>> ControllerArray;
ControllerArray createControllers();
