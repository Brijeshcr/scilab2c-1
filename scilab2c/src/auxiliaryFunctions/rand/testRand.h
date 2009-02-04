/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2007-2008 - INRIA - Bruno JOFRET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#ifndef __TESTRAND_H__
#define __TESTRAND_H__

#include <stdio.h>
#include <assert.h>
#include "rand.h"

#define ERROR 51

int srandsTest(void);

int drandsTest(void);
int drandaTest(void);
int crandsTest(void);

int zrandsTest(void);
int zrandaTest(void);
int testRand(void);

#endif /* ! __TESTRAND_H__ */
