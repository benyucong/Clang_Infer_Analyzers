/*
* File Name: Infer_not_good_at.c
* Defect Classification
* ---------------------
* Defect Type1: Numerical defects
* Defect Sub-type1: Bit shift bigger than integral type or negative

* Defect Type2: Numerical defects
* Defect Sub-type2: Integer precision lost because of cast

* Defect Type3: Pointer related defects
* Defect Sub-type3: Bad cast of a function pointer

* Defect Type4: Inappropriate code
* Defect Sub-type4: Dead code

* Defect Type5: Pointer related defects
* Defect Sub-type: Free NULL  pointer

* Description: Defect Code to identify defects of five types with 7 test cases
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

extern int idx, sink;
extern double dsink;
extern void *psink;

/*
 * Types of defects: bit shift error
 * Complexity: constant shift to the left beyond the int size
 */
void bit_shift_1()
{
    int a = 1;
    int ret;
    ret = a << 32; /*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
    sink = ret;
}

/*
 * Types of defects: bit shift error
 * Complexity: long	Beyond the size of the left shift - Constant
 */
void bit_shift_2()
{
    long a = 1;
    long ret;
    ret = a << 32; /*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
    sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: char	-> short	Variable
 */
void data_lost_1()
{
    char ret;
    short a = 0x80;
    ret = a; /*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
    sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: short-> int	Variable
 */

void data_lost_2()
{
    short ret;
    int a = 0x8000;
    ret = a; /*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
    sink = ret;
}

/*
 * Type of defect: Bad function pointer casting - Wrong return type
 * Complexity: different return type function :void and function pointer: int (no arguments)
 */
void func_pointer_001_func_1()
{
    int a;
    a = 10;
}

void func_pointer()
{
    int (*func)();
    int ret;
    func = (int (*)())func_pointer_001_func_1;
    ret = func(); /*Tool should detect this line as error*/ /*ERROR:Bad function pointer casting*/
}

/*
 * Types of defects: dead code
 * Complexity: the for statement	Constant
 */
void dead_code()
{
    int a = 0;
    int i;
    int ret;
    for (i = 0; i > 1; i++)
    {
        a++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
        break;
    }
    ret = a;
    sink = ret;
}

/*
 * Types of defects: Freeing a NULL pointer
 * Complexity: When using a pointer to char
 */
void free_null_pointer()
{
    char *buf = NULL;
    free(buf); /* Tool should detect this line as error */ /*ERROR:Freeing a NULL pointer*/
    buf = NULL;
}