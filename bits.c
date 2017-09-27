/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * <GAO ZHIYUAN, CA59>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
/*
 *  bitOr - returns x OR y, where x, y are integers
 */
int bitOr(int x, int y) {
  return ~(~x & ~y);
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
/*
 * isAsciiDigit - 
 */
int isAsciiDigit(int x) {
	int temp = ~(x>>31) & (x>>5) & ((x>>4)&0x1);//if it's a numbers smaller, return 0
	int k = (x+6)>>6;
	int check_k = !~(k ^ ~0);
  return temp & check_k;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
/*
 * getByte - returns the byte specfied 
 */
int getByte(int x, int n) {
	x = x >>  (n<<3);	
	/**x >> 8*n**/
	/*Clear the spare bits*/
  return x& 0xff;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	int shift1 = n<<3;
	int shift2 = m<<3;
	int k;
	int temp = x;
	/*Clear bits other than n byte*/
	int t = (x) & (0xff<<shift1);	
	/*Clear bits to 0 in m byte in x*/
	x = x & ~(0xff<<(shift2));
	/*Move t to the byte*/
	t = t >> shift1 << shift2 ;
	/*Clear redundent bits*/
	t = t & (0xff<<(shift2));


	/*Clear bits other than m byte*/
	k = (temp) & (0xff<<shift2);

	/*Clear bits to 0 in n byte in x*/
	x = x & ~(0xff<<(shift1));
	/*Move k to the byte*/
	k = k >> shift2 << shift1 ;	

	/*Clear redundent bits*/
	k = k & (0xff<<(shift1));
	/*Move t to x*/
	x = x | t | k;
	
    return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	/*Set MSB to 1 if x is not zero*/
	int t =  x | (~x + 1);
	t = (~t) >>31;
	return t & 0x01 ;
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
/* If x can be 16 bits, SB should be ffff
 * Or 0000
 * and bit 16 should be taken into consideration
 * */
	int t = x>>15;
	int f = ~0;
	return (!(~t)) | (!~(t ^ f));
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	int result =!(~(x^(x+1)));
  return (!(!(~x))) & result;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	int n = ~x +1;
	n = n^(0);
  return n;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
	int set_MSB = x | (~x+1);
	int cmp_MSB = (x ^ set_MSB)>>31 & 0x01;
	int if_neg = x>>31;
    return if_neg | cmp_MSB;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0, with overflow
 *            addOK(0x80000000,0x70000000) = 1, no overflow           
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
	int temp = x + y;
	int check1 = (temp ^ x) >>31 & 0x01;	
	int check2 = (temp ^ y) >>31 & 0x01;	
	int check3 = (!check1) & (!check2);
	int diff_sign = (x ^ y)>>31 & 0x01;
  return diff_sign | check3 ;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	/* The MSB*/
	int t = x>>31;
	/* Return 1 if is zero*/
	int is_zero = !~(x ^ ~0);
  return (!t) & (!is_zero);
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	int temp = x + x;
	/* Return ffffffff if sign changed, or 0 */
	int check_sign = (temp ^ x) >>31;
	int sign = x>>31;	
	int min = 0x1<<31;
	int max = ~min;
	int checker1 = temp & ~check_sign;
	int checker2 = min & sign & check_sign;
	int checker3 = max & check_sign & ~sign;
//	int s_zero = !~(x ^ ~0);
	/*(~(is_zero)+1) is ffffffff when x is not 0, 00000000 when x is 0*/
  //return (~(is_zero)+1) &  check_sign & (sign & min)    ;

	return checker1 | checker2 | checker3;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	int reverse = ~x+1;
	int check_minus = (x>>31) ;
	int check_pos = ~check_minus;
	return (reverse & check_minus) | (x & check_pos) ;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	int temp = 1<< 31;
	int reverse = uf ^ temp;

	int t1 = uf<<1;
	int t2 = t1>>24;
	int check_1 = ~t2;

	/* check_1 is zero if exp is 11111111 */
	if( !check_1 ){
		int check_2 = !(uf<<9);
		/* check_2 is zero, namely M is Non-zero, NaN*/
		if (!check_2)
			return uf;
	}
	/* else uf is not NaN*/
	

	return reverse;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
	int sign_f = uf;
	unsigned sf = uf;
	int result;
	unsigned exp = sf<<1>>24;
//	int zero_first_9 = ~(1<<31>>8);	
//	int sign = sf>>31;
//	int M = sf<<9>>9 ;
	int default_ = 1<<31;
	int i = default_;
	int temp_1 = ~(i>>8 & ~i) ;
	int temp_2 = sf & temp_1;

	/* Denormalized numbers' M shift to right one bit*/
	/* Normalized numbers smaller than FFFFFE(included) shift to be denormalized
	 * following the rule of shifting to even
	 * ex 800007->400004
	 * 800008->400004
	 * 800009->400004 */

	/* Larger Normalized numbers just decrease exp by 1 */
	/* Denormalized shift rightwards one bit */
	/* Normalized no larger than FFFFFF needs shift exp and round M */
	/* If %2 is 1, it needs rounding */
	if( exp <= 1u ) {
		result = sf>>1;
		if (sf%2 == 1){
			if ((result)%2 == 1){	
			result = result + 1;
			}
		}
			/* If /2 is odd(LSB is 1), it needs rounding up */			/* Now we need to clear the 31 bit up because of shifting */
		return (~(1<<30) & result) | (sf & 1<<31);
	}

	/* then it's normalized*/
	if ( ~(sign_f<<1>>24) == 0)
	/* if it is infinite*/
	/* or if it is NaN*/
		return uf;

	/* For a normalized larger number, we shift exp by 1*/
	exp = exp - 1;
	return (exp<<23) | temp_2 ;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	int sign_f = uf;
	unsigned sf = uf;
	int result;
	unsigned exp = sf<<1>>24;
	int default_ = 1<<31;

	if ( ~(sign_f<<1>>24) == 0)
	/* if it is infinite*/
	/* or if it is NaN*/
		return default_;
	if ( uf<<1 == 0)
		return 0;


	if( exp <= 0x7e ) {

		return 0;
	}
	if( exp >= 158){
		return default_;
	}
	
	
	exp = exp - 127;
	result = 1<<exp;
	if ( uf >= default_)
		return -result;
	else return result;

}
