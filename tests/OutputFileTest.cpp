#include <iostream>
#include <fstream>
#include <vector>
#include "Comparison.h"

using namespace std;

enum ErrorCodes
{
  Ok = 0,
  CouldNotOpenFile = 0x1,
  BadSimulationTimeOutput = 0x2,
  BadSimulationForwardEulerOutput = 0x4,
  BadSimulationBackwardEulerOutput = 0x8,
  BadSimulationTrapezoidalOutput = 0x10,
  FileGreaterThanExpected = 0x20,
  UnknownError = 0x40
};

class SimulationOutputTester
{
public:
  SimulationOutputTester()
    : MAX_PERCENT_ERROR(0.01)
  {
    _simulationOutput.push_back({0.0, 4.0, 4.0, 4.0});
    _simulationOutput.push_back({0.1, 3.0, 3.33, 3.2});
    _simulationOutput.push_back({0.2, 2.5, 2.89, 2.72});
    _simulationOutput.push_back({0.3, 2.25, 2.59, 2.43});
    _simulationOutput.push_back({0.4, 2.12, 2.4, 2.26});
    _simulationOutput.push_back({0.5, 2.06, 2.26, 2.16});
    _simulationOutput.push_back({0.6, 2.03, 2.18, 2.09});
    _simulationOutput.push_back({0.7, 2.02, 2.12, 2.06});
    _simulationOutput.push_back({0.8, 2.01, 2.08, 2.03});
    _simulationOutput.push_back({0.9, 2.0, 2.05, 2.02});
    _simulationOutput.push_back({1.0, 2.0, 2.03, 2.01});
  }

  int compareLine(size_t lineNumber, double time, double forward, double backward, double trapezoidal) const
  {
    if(lineNumber >= _simulationOutput.size())
      return FileGreaterThanExpected;

    int errorCode = Ok;
    const auto& simulationOutput = _simulationOutput.at(lineNumber);
    if(!compare(simulationOutput[0], time, MAX_PERCENT_ERROR))
      errorCode |= BadSimulationTimeOutput;
    if(!compare(simulationOutput[1], forward, MAX_PERCENT_ERROR))
      errorCode |= BadSimulationForwardEulerOutput;
    if(!compare(simulationOutput[2], backward, MAX_PERCENT_ERROR))
      errorCode |= BadSimulationBackwardEulerOutput;
    if(!compare(simulationOutput[3], trapezoidal, MAX_PERCENT_ERROR))
      errorCode |= BadSimulationTrapezoidalOutput;

    return errorCode;
  }
private:
  const double MAX_PERCENT_ERROR;

  vector< vector<double> > _simulationOutput;
};

int checkFile(istream& simulationOutput)
{
  if(simulationOutput)
  {
    //The first line should be the header, don't need to compare it to anything
    char header[256];
    simulationOutput.getline(header, 256);
  }

  SimulationOutputTester test;
  
  int errorCode = Ok;
  size_t line = 0;
  while(simulationOutput)
  {
    char value[256];
    simulationOutput.getline(value, 256, ',');
    double time = atof(value);
    simulationOutput.getline(value, 256, ',');
    double forward = atof(value);
    simulationOutput.getline(value, 256, ',');
    double backward = atof(value);
    simulationOutput.getline(value, 256);
    double trapezoidal = atof(value);

    if(!(line > 0 && time == 0.0))
      errorCode |= test.compareLine(line++, time, forward, backward, trapezoidal);
  }

  return errorCode;
}

void outputErrorCode(int errorCode)
{
  if(errorCode & BadSimulationTimeOutput)
    cerr << "Stepping in incorrect time-steps" << endl;
  if(errorCode & BadSimulationForwardEulerOutput)
    cerr << "Bad value for forward euler" << endl;
  if(errorCode & BadSimulationBackwardEulerOutput)
    cerr << "Bad value for backward euler" << endl;
  if(errorCode & BadSimulationTrapezoidalOutput)
    cerr << "Bad value for trapezoidal" << endl;
  if(errorCode & FileGreaterThanExpected)
    cerr << "Output file is of incorrect size (did you step simulate until stopTime and no more?)" << endl;
}

int main()
{
  try
  {
    ifstream simulationOutput("testOutput.csv");
    if(!simulationOutput)
    {
      cerr << "Could not open file" << endl;
      return CouldNotOpenFile;
    }

    int errorCode = checkFile(simulationOutput);
    outputErrorCode(errorCode);
    return errorCode;
  }
  catch(...)
  {
    cerr << "Unknown Error" << endl;
    return UnknownError;
  }
}