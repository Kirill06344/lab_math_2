#include <malloc.h>
#include "matrix_initialiaztion.h"

int get_index(const int row, const int col, const int size) {
  return row * size + col;
}

void init_matrix_a(double *a, const int size) {
  a[get_index(0, 1, size)] = 6;
  a[get_index(0, 2, size)] = -6;
  a[get_index(0, 3, size)] = -4;
  a[get_index(0, 4, size)] = -3;
  a[get_index(0, 5, size)] = -8;
  a[get_index(0, 6, size)] = -5;
  a[get_index(0, 7, size)] = 5;

  a[get_index(1, 0, size)] = 6;
  a[get_index(1, 1, size)] = -13;
  a[get_index(1, 2, size)] = -3;
  a[get_index(1, 3, size)] = 5;
  a[get_index(1, 4, size)] = 4;
  a[get_index(1, 5, size)] = 3;
  a[get_index(1, 6, size)] = 1;
  a[get_index(1, 7, size)] = 7;

  a[get_index(2, 0, size)] = 5;
  a[get_index(2, 1, size)] = -5;
  a[get_index(2, 2, size)] = -1;
  a[get_index(2, 3, size)] = 7;
  a[get_index(2, 4, size)] = 2;
  a[get_index(2, 5, size)] = 0;
  a[get_index(2, 6, size)] = 7;
  a[get_index(2, 7, size)] = 1;

  a[get_index(3, 0, size)] = 5;
  a[get_index(3, 1, size)] = -5;
  a[get_index(3, 2, size)] = 5;
  a[get_index(3, 3, size)] = 6;
  a[get_index(3, 4, size)] = 4;
  a[get_index(3, 5, size)] = -7;
  a[get_index(3, 6, size)] = 4;
  a[get_index(3, 7, size)] = 0;

  a[get_index(4, 0, size)] = 4;
  a[get_index(4, 1, size)] = 4;
  a[get_index(4, 2, size)] = 7;
  a[get_index(4, 3, size)] = -4;
  a[get_index(4, 4, size)] = 9;
  a[get_index(4, 5, size)] = -8;
  a[get_index(4, 6, size)] = -8;
  a[get_index(4, 7, size)] = -4;

  a[get_index(5, 0, size)] = -4;
  a[get_index(5, 1, size)] = 5;
  a[get_index(5, 2, size)] = -4;
  a[get_index(5, 3, size)] = 1;
  a[get_index(5, 4, size)] = 0;
  a[get_index(5, 5, size)] = 12;
  a[get_index(5, 6, size)] = 0;
  a[get_index(5, 7, size)] = 6;

  a[get_index(6, 0, size)] = -3;
  a[get_index(6, 1, size)] = -2;
  a[get_index(6, 2, size)] = -4;
  a[get_index(6, 3, size)] = 2;
  a[get_index(6, 4, size)] = -8;
  a[get_index(6, 5, size)] = -3;
  a[get_index(6, 6, size)] = 16;
  a[get_index(6, 7, size)] = 4;

  a[get_index(7, 0, size)] = 7;
  a[get_index(7, 1, size)] = 5;
  a[get_index(7, 2, size)] = 0;
  a[get_index(7, 3, size)] = 2;
  a[get_index(7, 4, size)] = 0;
  a[get_index(7, 5, size)] = -6;
  a[get_index(7, 6, size)] = 8;
  a[get_index(7, 7, size)] = -12;
}

void init_matrix_b(double *b) {
  b[1] = 133;
  b[2] = 110;
  b[3] = 112;
  b[4] = 17;
  b[5] = 32;
  b[6] = 13;
  b[7] = -18;
}

double *create_transproted_matrix(double *a, const int size) {
  double * res = malloc(sizeof(double) * size * size);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      res[get_index(i, j, size)] = a[get_index(j, i, size)];
      res[get_index(j, i, size)] = a[get_index(i, j, size)];
    }
  }
  return res;
}

double * get_matrix_product(double * a, double * b, int a_rows, int a_cols, int b_rows, int b_cols) {
  double * res = malloc(sizeof(double) * a_rows * b_cols);
  for (int i = 0; i < a_rows; ++i) {
    for (int j = 0; j < b_cols; ++j) {
      for (int k = 0; k < a_cols; ++k) {
        res[i * a_rows + j] += a[i * a_rows + k] * b[k * b_cols + j];
      }
    }
  }
  return res;
}
