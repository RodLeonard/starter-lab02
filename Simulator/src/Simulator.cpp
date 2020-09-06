#include "Simulator.h"
#include "NumericalIntegration.h"

using namespace std;
using namespace ELCT350::NumericalIntegration;

namespace ELCT350
{
  namespace Simulator
  {
    void outputHeader(ostream& output)
    {
      //TODO: Write header to output
    }

    void outputStep(double time, double forward, double backward, double trapezoidal, std::ostream& output)
    {
      //TODO: Write output of the current time for all integration methods
    }

    void runSimulation(double timeStep, double stopTime, ostream& output)
    { 
      outputHeader(output);

      //TODO: Run simulation from 0 to stopTime at given timeStep, write result to output
    }
  }
}