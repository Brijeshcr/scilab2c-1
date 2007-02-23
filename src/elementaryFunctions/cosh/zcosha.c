/*
**  -*- C -*-
**
** zcosha.c
** Made by  Bruno JOFRET <bruno.jofret@inria.fr>
**
** Started on  Thu Dec  7 16:12:02 2006 jofret
** Last update Fri Feb 23 16:42:40 2007 jofret
**
** Copyright INRIA 2006
*/

#include "cosh.h"

void zcosha(doubleComplex* x, int strideX, doubleComplex* y, int strideY, int size) {
  int i = 0;
  for (i = 0; i < size; ++i) {
    y[i] = zcoshs(x[i]);
  }
}
