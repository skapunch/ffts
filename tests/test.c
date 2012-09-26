/*
 
 This file is part of SFFT.
  
 Copyright (c) 2012, Anthony M. Blake
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 	* Redistributions of source code must retain the above copyright
 		notice, this list of conditions and the following disclaimer.
 	* Redistributions in binary form must reproduce the above copyright
 		notice, this list of conditions and the following disclaimer in the
 		documentation and/or other materials provided with the distribution.
 	* Neither the name of the organization nor the
	  names of its contributors may be used to endorse or promote products
 		derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL ANTHONY M. BLAKE BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <stdio.h>
#include <complex.h>
#include <xmmintrin.h>

#include "ffts.h"

int
main(int argc, char *argv[]) {
  int i;
  int n = atoi(argv[1]);
 	int sign = atoi(argv[2]);

	float complex __attribute__ ((aligned(32))) *input = _mm_malloc(n * sizeof(float complex), 32);
  float complex __attribute__ ((aligned(32))) *output = _mm_malloc(n * sizeof(float complex), 32);

	for(i=0;i<n;i++) input[i] = i;

	ffts_plan_t *p = ffts_init(i, sign);
	if(p) {
	
  	p->transform(p, input, output);
  	for(i=0;i<n;i++) printf("%d %f %f\n", i, creal(output[i]), cimag(output[i]));
  	ffts_free(p);
	
	}else{
		printf("Plan unsupported\n");
	}

  return 0;
}
