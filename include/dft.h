#include <math.h>
#include "../include/complex.h"

#ifndef DFT_H
#define DFT_H

static float comp(float);
static float real(float);
void dft(float*, Complex*, int);
void inverse_dft(Complex*, float*, int);

// Return complex part of e^phi
static inline float comp(float phi) {
  return sin(phi);
}

// Return real part of e^phi
static inline float real(float phi) {
  return cos(phi);
}

#endif
