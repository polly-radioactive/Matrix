#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = S21_SUCCESS;
  double tmp;
  if (check_matrix(A) && result != 0 && s21_determinant(A, &tmp) == 0) {
    if (tmp != 0) {
      matrix_t C;
      s21_calc_complements(A, &C);
      s21_transpose(&C, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] *= -1;
        }
      }
      s21_remove_matrix(&C);
    } else {
      status = S21_MATH_OPERATIONS_ERROR;
    }
  } else {
    status = S21_INVALID_MATRIX;
  }
  return status;
}