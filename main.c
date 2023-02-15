#include <stdio.h>
#include <malloc.h>
#include "cmath.h"
#include "matrix_initialiaztion.h"

const int MATRIX_SIZE = 8;

int get_index_1(const int row, const int col, const int size) {
  return row * size + col;
}

double *create_transproted_matrix_1(double *a, const int size) {
  double * res = malloc(sizeof(double) * size * size);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      res[get_index_1(i, j, size)] = a[get_index_1(j, i, size)];
      res[get_index_1(j, i, size)] = a[get_index_1(i, j, size)];
    }
  }
  return res;
}

int main() {
  double a[MATRIX_SIZE * MATRIX_SIZE], b[MATRIX_SIZE];
  double cond, p = 1.0;
  int n, pivot[MATRIX_SIZE], flag;

  init_matrix_a(a, MATRIX_SIZE);
  init_matrix_b(b);
  n = MATRIX_SIZE;

  while (p >= 0.000001) {
    printf("p=%lf \n", p);
    a[0] = p - 29;
    b[0] = 4 * p - 175;

    decomp(n, MATRIX_SIZE, a, &cond, pivot, &flag);
    printf ("%s\n", cmathmsg(DECOMP_C, flag));
    if (flag == 0) {
      solve(n, MATRIX_SIZE, a, b, pivot);
      printf ("Solution: [");
      for(int i = 0; i < n; i++) printf ("%lf, ", b[i]);
      printf ("]\n");
      printf ("Condition number = %e\n", cond);
    }
    printf("------------------\n");
    double * t_a = create_transproted_matrix_1(a, MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE;++i){
      printf("%d ", t_a[i]);
      if (i == MATRIX_SIZE) {
        printf("\n");
      }
    }
    double * tmp_left = get_matrix_product(t_a, a, MATRIX_SIZE,MATRIX_SIZE, MATRIX_SIZE, MATRIX_SIZE);
    decomp(n, MATRIX_SIZE, tmp_left, &cond, pivot, &flag);
    printf ("%s\n", cmathmsg(DECOMP_C, flag));
    if (flag == 0) {
      double * tmp_right = get_matrix_product(t_a, b, MATRIX_SIZE,MATRIX_SIZE, MATRIX_SIZE, 1);
      solve(n, MATRIX_SIZE, tmp_left, tmp_right, pivot);
      printf ("Solution: [");
      for(int i = 0; i < n; i++) printf ("%lf, ", tmp_right[i]);
      printf ("]\n");
      printf ("Condition number = %e\n", cond);
    }
    printf("------------------\n");

    p /= 10;
  }


}
