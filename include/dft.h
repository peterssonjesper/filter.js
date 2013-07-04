#include "../include/complex.h"

#ifndef DFT_H
#define DFT_H

float comp(int, int, int);
float real(int, int, int);
extern void dft(float*, Complex*, int);

#endif
