/*
 **************************************************************************************
 *       Filename:  main.c
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2018-06-29 14:56:36
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */


#include	<stdlib.h>
#include    <stdarg.h>
#include    <stdio.h>

typedef __builtin_va_list           va_list_beta;
#define va_start_beta(ap,v)         (__builtin_va_start(ap, v))
#define va_arg_beta(ap, type)       (__builtin_va_arg(ap, type))
#define va_end_beta(ap)             ((void)0)

static int sum_varargs_func_beta ( int count, ... )
{
    int sum = 0;
    va_list_beta vp;
    printf("count = %d\n", count);
    va_start_beta(vp, count);
    for(int i = 0; i < count; i++) {
        sum += va_arg_beta(vp, int); // 获得vp指向实参的值，然后vp指向next一个实参的值
    }

    va_end_beta(vp); // vp = null;

    return sum;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sum_varargs_func
 *  Description:  
 * =====================================================================================
 */
static int sum_varargs_func ( int count, ... )
{
    int sum = 0;
    va_list vp;
    // vp指向第二个参数的地址，即count的下一个实参的addr
    va_start(vp, count);
    for(int i = 0; i < count; i++) {
        printf("vp: %p\n", vp);
        sum += va_arg(vp, int); // 获得vp指向实参的值,然后vp指向next一个实参的地址,实测vp并没有变化
    }

    va_end(vp);

    return sum;
}
/* -----  end of static function sum_varargs_func  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description: main 
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    int value = 0;
    value = sum_varargs_func(5, 1, 2, 3, 4, 5);
    printf("sum = %d\n", value);
    value = sum_varargs_func_beta(5, 1, 2, 3, 4, 5);
    printf("sum beta = %d\n", value);

    return EXIT_SUCCESS;
}
/* ----------  end of function main  ---------- */



/********************************** END **********************************************/

