#include "9.h"

double power(double x, int n)
{
  double tmp = 1;
  for (int i = 0; i < n; i++)
  {
    tmp *= x;
  }
  return tmp;
}