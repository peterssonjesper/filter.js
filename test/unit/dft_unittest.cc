#include <limits.h>
#include "../../include/dft.h"
#include "../../include/complex.h"
#include "../../gtest/include/gtest/gtest.h"

#define ROUNDING_ERROR 1e-7

TEST(DFT, no_samples) {
  float *samples = 0;
  Complex *output = 0;
  int length = 0;

  dft(samples, output, length);
}

TEST(DFT, one_sample) {
  float samples[1] = { 0 };
  Complex output[1];
  int length = 1;

  dft(samples, output, length);

  EXPECT_NEAR(output[0].r, 0, ROUNDING_ERROR);
  EXPECT_NEAR(output[0].c, 0, ROUNDING_ERROR);
}

TEST(DFT, two_samples) {
  float samples[2] = { -1, 1 };
  Complex output[2];
  int length = 2;

  dft(samples, output, length);

  EXPECT_NEAR(output[0].r, 0, ROUNDING_ERROR);
  EXPECT_NEAR(output[0].c, 0, ROUNDING_ERROR);

  EXPECT_NEAR(output[1].r, -2, ROUNDING_ERROR);
  EXPECT_NEAR(output[1].c, 0, ROUNDING_ERROR);
}
