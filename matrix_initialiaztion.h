#ifndef MATRIX_INITIALIAZTION_H
#define MATRIX_INITIALIAZTION_H

void init_matrix_a(double* a, const int size);
void init_matrix_b(double * b);
double * create_transproted_matrix(double * a,const int size);
double * get_matrix_product(double * a, double * b, int a_rows, int a_cols, int b_rows, int b_cols);
#endif
