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

#ifndef __DIVISION_H__
#define __DIVISION_H__

#include "floatComplex.h"
#include "doubleComplex.h"


/*
**
** WARNING WE ASSUME MATRIXES TO BE CONSCISTENT
** size1 = size2;
**
*/


/*
** RIGHT DIVISION
*/

/*
** \brief Compute a right division for floats.
** \param in1 : input float.
** \param in2 : input float.
** \return in1 / in2 = in1 ./ in2.
*/
float srdivs (float in1, float in2);

/*
** \brief Compute a right division element ways for floats.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 ./ in2.
*/
void srdiva (float* in1, float* in2, int size, float* out );

/*
** \brief Compute a right division for double.
** \param in1 : input double.
** \param in2 : input double.
** \return in1 / in2 = in1 ./ in2.
*/
double drdivs (double in1, double in2);

/*
** \brief Compute a right division element ways for double.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 ./ in2.
*/
void drdiva (double* in1, double* in2, int size, double* out );

/*
** \brief Compute a right division for floats complex.
** \param in1 : input float complex.
** \param in2 : input float complex.
** \return in1 / in2 = in1 ./ in2.
*/
floatComplex crdivs (floatComplex in1, floatComplex in2);

/*
** \brief Compute a right division element ways for float complex.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 ./ in2.
*/
void crdiva(floatComplex* in1, floatComplex* in2, int size, floatComplex* out );

/*
** \brief Compute a right division for double complex.
** \param in1 : input double complex.
** \param in2 : input double complex.
** \return in1 / in2 = in1 ./ in2.
*/
doubleComplex zrdivs (doubleComplex in1, doubleComplex in2);

/*
** \brief Compute a right division element ways for double complex.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 ./ in2.
*/
void zrdiva(doubleComplex* in1, doubleComplex* in2, int size, doubleComplex* out );

/*
** LEFT DIVISION
*/

/*
** \brief Compute a left division for floats.
** \param in1 : input float.
** \param in2 : input float.
** \return in1 \ in2 = in1 .\ in2.
*/
float sldivs (float in1, float in2);

/*
** \brief Compute a left division element ways for floats.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 .\ in2.
*/
void sldiva (float* in1, float* in2, int size, float* out );

/*
** \brief Compute a left division for double.
** \param in1 : input double.
** \param in2 : input double.
** \return in1 \ in2 = in1 .\ in2.
*/
double dldivs (double in1, double in2);

/*
** \brief Compute a left division element ways for double.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 .\ in2.
*/
void dldiva (double* in1, double* in2, int size, double* out );

/*
** \brief Compute a left division for floats complex.
** \param in1 : input float complex.
** \param in2 : input float complex.
** \return in1 \ in2 = in1 .\ in2.
*/
floatComplex cldivs (floatComplex in1, floatComplex in2);

/*
** \brief Compute a left division element ways for float complex.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 .\ in2.
*/
void cldiva(floatComplex* in1, floatComplex* in2, int size, floatComplex* out );

/*
** \brief Compute a left division for double complex.
** \param in1 : input double complex.
** \param in2 : input double complex.
** \return in1 \ in2 = in1 .\ in2.
*/
doubleComplex zldivs (doubleComplex in1, doubleComplex in2);

/*
** \brief Compute a left division element ways for double complex.
** \param in1 : input array.
** \param in2 : input array.
** \param size : size of in2 array = rows*columns.
** \param out : array that contains the division in1 .\ in2.
*/
void zldiva(doubleComplex* in1, doubleComplex* in2, int size, doubleComplex* out );



#endif /* !__DIVISION_H__ */
