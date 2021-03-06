#include "../include/dft.h"

void dft(float *samples, Complex *output, int length) {
  for(int k = 0; k < length; ++k) {
    output[k].c = 0;
    output[k].r = 0;
    for(int n=0; n<length; ++n) {
      // e ^-phi = e^-(2*pi*i / length * n * k)
      float phi = - 2.0 * M_PI * n * k / length;
      output[k].r += samples[n] * real(phi);
      output[k].c += samples[n] * comp(phi);
    }
  }
}

void inverse_dft(Complex *samples, float *output, int length) {
  for(int n = 0; n < length; ++n) {
    output[n] = 0;
    for(int k=0; k<length; ++k) {
      float phi = - 2.0 * M_PI * n * k / length;
      output[n] += (samples[k].r * real(phi) - samples[k].c * comp(phi));
    }
    output[n] /= length;
  }
}
