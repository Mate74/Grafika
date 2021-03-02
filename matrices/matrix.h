#ifndef MATRIX_H
#define MATRIX_H

void init_zero_matrix(float matrix[3][3]);

void print_matrix(float matrix[3][3]);

void print_vektor(float vektor[3]);

void add_matrices(float result[3][3],float a[3][3],float b[3][3]);

void init_identity_matrix(float matrix[3][3]);

void multiply_matrix_with_skalar(float result[3][3],float matrix[3][3], float skalar);

void multiply_matrices(float result[3][3], float matrix_a[3][3],float matrix_b[3][3]);

void transform_point(float result[3],float matrix[3][3],float point[3]);

void shift(float result[3][3],float matrix[3][3]);

void rotate(float result[3][3],float matrix[3][3]);

void scale (float result[3][3],float matrix[3][3]);

#endif // MATRIX_H

