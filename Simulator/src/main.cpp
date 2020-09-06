#include <iostream>
#include <fstream>
#include "Simulator.h"

using namespace std;
using namespace ELCT350::Simulator;

enum ErrorCodes
{
  Ok = 0,
  IncorrectUsage = 0x1,
  CouldNotOpenFile = 0x2
};

int main(int argc, char* argv[])
{
  if(argc != 4)
  {
    cerr << "USAGE: " << argv[0] << "<time step> <stop time> <output file>" << endl;
    return IncorrectUsage;
  }

  double timeStep = atof(argv[1]);
  double stopTime = atof(argv[2]);
  const char* outputFilePath = argv[3];

  //TODO: Run the simulation here:
  return Ok;
}