#include <limits.h>
#include "../../include/dft.h"
#include "../../gtest/include/gtest/gtest.h"

#define ROUNDING_ERROR 1e-7

TEST(DFT, no_samples) {
  float samples[1] = { 0 };
  float output_complex[1] = { 0 };
  float output_real[1] = { 0 };
  int length = 0;

  dft(samples, output_real, output_complex, length);

  EXPECT_NEAR(output_real[0], 0, ROUNDING_ERROR);
  EXPECT_NEAR(output_complex[0], 0, ROUNDING_ERROR);
}

TEST(DFT, one_sample) {
  float samples[1] = { 0 };
  float output_complex[1];
  float output_real[1];
  int length = 1;

  dft(samples, output_real, output_complex, length);

  EXPECT_NEAR(output_real[0], 0, ROUNDING_ERROR);
  EXPECT_NEAR(output_complex[0], 0, ROUNDING_ERROR);
}

TEST(DFT, two_samples) {
  float samples[2] = { -1, 1 };
  float output_complex[2];
  float output_real[2];
  int length = 2;

  dft(samples, output_real, output_complex, length);

  EXPECT_NEAR(output_real[0], 0, ROUNDING_ERROR);
  EXPECT_NEAR(output_complex[0], 0, ROUNDING_ERROR);

  EXPECT_NEAR(output_real[1], -2, ROUNDING_ERROR);
  EXPECT_NEAR(output_complex[1], 0, ROUNDING_ERROR);
}
