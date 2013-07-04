#include <math.h>
#include "../include/dft.h"

float comp(int n, int k, int length) {
  float phi = 2.0 * M_PI * float(n) * float(k) / float(length);
  return sin(phi);
}

float real(int n, int k, int length) {
  float phi = 2.0 * M_PI * n * k / length;
  return cos(phi);
}

void dft(float *x, Complex *y, int length) {

  for(int k = 0; k < length; ++k) {
    y[k].c = 0;
    y[k].r = 0;
    for(int n=0; n < length; ++n) {
      // e ^ -(2*pi*i / length * n * k)
      y[k].r += x[n] * real(n, k, length);
      y[k].c += x[n] * comp(n, k, length);
    }
  }

}
