/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  return ~(~x & ~y) & ~(x & y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{

  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // -1 has the same representation with UMAX
  if (x ==-1)
    return 0;
  // 01111+1 = 10000
  // 10000+01111 = 11111
  int val = x + 1 + x;
  // check whether ~val == 00000
  return !~val;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int val = 0xAAAAAAAA;
  // use & with val will make sure the numbers on all the odd postions are 1
  return ((x & val) == val);

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

///////////////////////////////////////////////////////////////////////////////////////////////////////
// bu hui

// A + neg A = 0     A + ~A = -1
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // check whether the first two digits are "11"
  int first_two_check = (x >> 4) == 3;
  // if the value is in the given range, then this check will yield a negative value
  int last_four_check = x + ~0x3A+1;
  // if it is negative, then the sign_check would be 1111111....
  int sign_check = last_four_check >> 31;
  return first_two_check & !(sign_check + 1);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // convert x to true or false
  int temp = !x;
  // if x is zero, temp is 1. Otherwise, temp is 0
  // ~temp+1 can generate 000000000000 or 1111111111111
  // if x is zero, the temp2 is 111111111111111
  int temp2 = ~temp + 1;
  // one side is the value we want, the other side is 0
  return (temp2 & z) | (~temp2 & y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // get the sign of x and y
  int x_sign = (x >> 31) & 1;
  int y_sign = (y >> 31) & 1;
  // check whether x <0 and y>=0
  // otherwise y-x may greater than the limit
  // only the aiming situation can creats 1
  int check_1 = x_sign & (~y_sign);
  //check the sign of y-x
  // produce 1 is y-x >= 0
  int val = y + ~x+1;
  int sign_check = !(1 & (val >> 31));
  // to make sure all the x and y enter this part doesn't
  // fit check 1
  // it produce 1 when x and y have same sign
  int enter_check = !(x_sign ^ y_sign);
  return check_1 | (enter_check & sign_check);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int x_sign = 1 & (x >> 31);
  // The maximum value has 0111111.....
  int Max_val = ~(1 << 31);
  // if x>0 && x != 0, then x + max should still be negative
  int x_alt = x + Max_val;
  int x_alt_sign = 1 & (x_alt >> 31);
  return (1^x_sign) & (1^x_alt_sign);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // a float point consists of 1|8|23
  // exponent is represented by the 8 bits in the middle
  int exp = (uf >> 23) & 255;
  // sign is the first bit
  // there is no need to get the exact sign value at here
  // easier to use VALUE | sign in the end
  int sign = uf & (1 << 31);
  // frac term
  // the hex expression of 11..111(23) is 7fffff
  int frac = uf & 0x7fffff;
  // check whether uf equals NaN
  // NAN is obtained when exp == 255  (1111111)
  if (exp == 255)
    return uf;
  // check whetehr is using the denormalized form
  if (exp == 0) {
    // in this form, only need to deal with the frac term
    // in binary representation, 2* frac is same with frac<<1
    return (frac << 1) | sign;
  }
  int new_exp = exp+1;
  // check whether adding one leads to NAN
  if (new_exp == 255){
    return sign | (255 << 23);
  }
  // join the three parts together
  return sign | ((new_exp << 23) + frac);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
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
int floatFloat2Int(unsigned uf) {
  // a float point consists of 1|8|23
  // exponent is represented by the 8 bits in the middle
  int exp = (uf >> 23) & 255;
  // sign is the first bit
  int sign = (uf>>31) & 1;
  //int frac = uf & 0x7fffff--111...(23);
  int frac = uf  & 0xffffff;
  // the leading 1 should be added
  frac = frac | (1 << 23);
  // check whether uf equals NaN
  // NAN is obtained when exp == 255  (1111111)
  if (exp == 255)
    return 0x80000000u;
  // check whetehr is 0
  if (exp == 0x0)
  {
    return 999999999;   ///////////////////////////////////////////////////////////////////
  }
  // minus the bias
  int new_exp = exp - 127;
  // check whether overflow happens
  if (new_exp >= 32)
    return 0x80000000u;
  // shift to right of left
  if (new_exp>23)
    frac = frac << (new_exp - 23);
  else
    frac = frac >> (new_exp - 23);
  if (sign)
    return -frac;
  else
    return frac;
}

/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // add bias
  int exp = x + 127;
  // check whether is too small
  if (exp <= 0)
    return 0;
  // check whether is too large
  // inf can be expressed as 111..(8)0000..(23)
  if (exp >= 255)
    return (0xFF << 23);
  return exp << 23;
}