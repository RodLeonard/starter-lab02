#pragma once
#include <cmath>

bool compare(double expectedValue, double experimentalValue, double maxPercentError)
{
  double percentError = 0.0;
  if(expectedValue == 0.0 && experimentalValue == 0.0)
    return true;

  if(expectedValue == 0.0)
    percentError = fabs(expectedValue - experimentalValue) / experimentalValue;
  else
    percentError = fabs((expectedValue - experimentalValue) / expectedValue);
  return percentError <= maxPercentError;
}