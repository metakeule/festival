/*************************************************************************/
/*                                                                       */
/*                Centre for Speech Technology Research                  */
/*                     University of Edinburgh, UK                       */
/*                       Copyright (c) 1996,1997                         */
/*                        All Rights Reserved.                           */
/*                                                                       */
/*  Permission is hereby granted, free of charge, to use and distribute  */
/*  this software and its documentation without restriction, including   */
/*  without limitation the rights to use, copy, modify, merge, publish,  */
/*  distribute, sublicense, and/or sell copies of this work, and to      */
/*  permit persons to whom this work is furnished to do so, subject to   */
/*  the following conditions:                                            */
/*   1. The code must retain the above copyright notice, this list of    */
/*      conditions and the following disclaimer.                         */
/*   2. Any modifications must be clearly marked as such.                */
/*   3. Original authors' names are not deleted.                         */
/*   4. The authors' names are not used to endorse or promote products   */
/*      derived from this software without specific prior written        */
/*      permission.                                                      */
/*                                                                       */
/*  THE UNIVERSITY OF EDINBURGH AND THE CONTRIBUTORS TO THIS WORK        */
/*  DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING      */
/*  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT   */
/*  SHALL THE UNIVERSITY OF EDINBURGH NOR THE CONTRIBUTORS BE LIABLE     */
/*  FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    */
/*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN   */
/*  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,          */
/*  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF       */
/*  THIS SOFTWARE.                                                       */
/*                                                                       */
/*************************************************************************/
/*             Author :  Steve Isard and Alistair Conkie                 */
/*             Date   :  1984 and 1996                                   */
/*  This version was gifted by Steve for this new                        */
/*  copyright, the original retains their original copyright             */
/*                                                                       */
/*************************************************************************/
#include <math.h>
#include <stdio.h>
#include "t2s.h"

#define SQRTSIX 0.408248

int don_random_seed = 1;

static short ial(void);

/* 
	wkspace[0] pitch period index
	wkspace[1] where in pitch period
*/

float iexc(short voiced, ACOUSTIC *as, short *wkspace)
{
	switch(wkspace[1]) {
		case 0: 
			wkspace[1] = as->pitch[wkspace[0]++] - 1; 
			if(voiced)
				return((float)SQRTSIX);
			break;
		case 1: 
			wkspace[1]--;
			if(voiced)
				return((float)2*(float)SQRTSIX);	// YK 2011-07-25 typecast to float
			break;
		case 2: 
			wkspace[1]--;
			if(voiced)
				return((float)SQRTSIX);
			break;
		default: 
			wkspace[1]--;
			if(voiced)
				return((float)0);
			break;
	}
	return( (float)(ial()) - (float)0.5);	// YK 2011-07-25 typecast to float

}

static short ial()	/* random number generator  */
{
    int seed = don_random_seed;
    short i1,i2,i3;

    i1 = 1&(seed);
    i2 = (((seed)&4) >> 2);
    i3 = i1^i2;
    seed = (((seed) >> 1) + (i3 << 10));
    don_random_seed = seed;
    return(i3);
}
