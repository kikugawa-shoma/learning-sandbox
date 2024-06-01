#include <gtest/gtest.h>

bool returnFalse(){
  return false;
}

TEST(IsEvenTest, Negative)
{
  EXPECT_FALSE(returnFalse());
}
