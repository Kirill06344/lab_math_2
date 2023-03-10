///* decompd.c
//   Sample driver for decomp() and solve().
//*/
//
//#include <math.h>
//#include <stdio.h>
//#include "cmath.h"
//
//#define mdim 10
//#define get_index(i, j)  (i) * mdim + (j)
//
//int main ()
//{
//static double a[mdim * mdim], b[mdim], cond;
//double det;
//int n, pivot[mdim], i, flag;
//double s;
//
//n       = 3;
//s       = 1.0e-6;  /* as s ---> 0.0, matrix becomes singular */
//b[0]    = 5.0;   b[1]    = 15.0+s; b[2]    = 10.0;
//
//a[get_index(0,0)] = 1.0;   a[get_index(0,1)] = 2.0;    a[get_index(0,2)] = 2.0;
//a[get_index(1,0)] = 2.0+s; a[get_index(1,1)] = 9.0;    a[get_index(1,2)] = 4.0;
//a[get_index(2,0)] = 1.0;   a[get_index(2,1)] = 7.0;    a[get_index(2,2)] = 2.0;
//
//printf ("\n\n  --- CMATH --- Design Software 1989\n");
//printf ("\nTest driver for decomp() and solve().\n\n");
//
//decomp (n, mdim, a, &cond, pivot, &flag);
//printf ("%s\n", cmathmsg(DECOMP_C, flag));
//
//if (flag == 0)
//   {
//   solve (n, mdim, a, b, pivot);
//
//   printf ("Solution    =     [ ");
//   for(i = 0; i < n; i++) printf ("%8.3f, ", b[i]);
//   printf ("]\n");
//   printf ("Correct answer is [    1.000,    1.000,    1.000, ]\n");
//
//   printf ("\n");
//   printf ("Condition number = %e\n", cond);
//
//   det = pivot[n-1];
//   for (i = 0; i < n; i++)
//      det = det * a[get_index(i,i)];
//   printf ("\nDeterminant  = %f\n", det);
//   }
//
//return (0);
//}
//
