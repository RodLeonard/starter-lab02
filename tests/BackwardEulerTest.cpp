#include "NumericalIntegration.h"
#include "Comparison.h"

using namespace ELCT350::NumericalIntegration;

enum ErrorCodes
{
  Ok = 0,
  IncorrectValue = 0x1,
  UnknownError = 0x2
};

int main()
{
  int errorCode = Ok;
  try
  {
    if(!compare(2.16, backwardEuler(2.57, 0.5), 0.01))
      errorCode |= IncorrectValue;
  }
  catch(...)
  {
    errorCode |= UnknownError;
  }

  return errorCode;
}