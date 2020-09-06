#pragma once

namespace ELCT350
{
  namespace NumericalIntegration
  {
    double forwardEuler(double currentState, double timeStep);
    double backwardEuler(double currentState, double timeStep);
    double trapezoidal(double currentState, double timeStep);
  }
}