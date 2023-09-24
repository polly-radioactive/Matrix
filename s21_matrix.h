#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define eps 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum S21_MATRIX_CODE {
  S21_SUCCESS = 0,
  S21_INVALID_MATRIX = 1,
  S21_MATH_OPERATIONS_ERROR = 2
};

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int matrix_check(matrix_t *A, matrix_t *B);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int print_matrix(matrix_t *A);
int check_matrix(matrix_t *A);
int minor_i(matrix_t *A, int rows_m, int columns_m, matrix_t *C);
double square_determinant(matrix_t *A);
int algebraic_addition(int rows_m, int columns_m);
void calc_minor(double **A, double **C, int rows_m, int columns_m, int size);
double calc_det(matrix_t *A, int size);