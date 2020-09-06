#pragma once
#include <ostream>

namespace ELCT350
{
  namespace Simulator
  {
    void runSimulation(double timeStep, double stopTime, std::ostream& output);
  }
}