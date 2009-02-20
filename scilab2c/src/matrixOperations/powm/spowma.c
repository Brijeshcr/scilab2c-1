/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2008 - INRIA - Arnaud TORSET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#include "matrixPow.h"
#include "spec.h"
#include "pow.h"
#include "matrixTranspose.h"
#include "conj.h"
#include "matrixInversion.h"
#include "matrixMultiplication.h"

void spowma(float* in, int rows, float power, floatComplex* out){
	int i=0, j=0;
	int symmetric=0;
	floatComplex *eigenvalues,*eigenvectors,*tmp;
	
	/* Data initialization */
	eigenvalues = malloc((uint)(rows*rows)*sizeof(floatComplex));
	eigenvectors = malloc((uint)(rows*rows)*sizeof(floatComplex));
	tmp = malloc((uint)(rows*rows)*sizeof(floatComplex));
	
	/* symmetric test*/
	for(i=0;i<rows;i++) {
		for (j=0;j<rows;j++)
			if (in[i*rows+j]!=in[j*rows+i]) break;
		
		if (j!=rows) break;
	}
	
	if ((i==rows)&&(j==rows)) symmetric=1;
	
	
	/* find eigenvalues and eigenvectors */
	sspec2a(in, rows, eigenvalues,eigenvectors);
	
	/* make operation on eigenvalues and eigenvectors */
	for (i=0;i<rows;i++)
			eigenvalues[i+i*rows]=cpows(eigenvalues[i+i*rows],FloatComplex(power,0));
			
	cmulma(eigenvectors, rows, rows, eigenvalues, rows, rows, tmp);
	
	if (symmetric){		
		ctransposea(eigenvectors, rows,rows, eigenvalues);
		cconja(eigenvalues, rows*rows, eigenvalues);
	}
	else cinverma(eigenvectors, eigenvalues, rows);
	
	cmulma(tmp, rows, rows, eigenvalues, rows, rows, out);
	
	free(eigenvalues);
	free(eigenvectors);
	free(tmp);
	
}