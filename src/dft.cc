#include <math.h>

float comp(int n, int k, int length) {
  float phi = 2.0 * M_PI * float(n) * float(k) / float(length);
  return sin(phi);
}

float real(int n, int k, int length) {
  float phi = 2.0 * M_PI * n * k / length;
  return cos(phi);
}

void dft(float *x, float *y_real, float *y_comp, int length) {

  for(int k=0; k < length; ++k) {
    y_comp[k] = 0;
    y_real[k] = 0;
    for(int n=0; n < length; ++n) {
      // e ^ -(2*pi*i / length * n * k)
      y_comp[k] += x[n] * comp(n, k, length);
      y_real[k] += x[n] * real(n, k, length);
    }
  }

}
