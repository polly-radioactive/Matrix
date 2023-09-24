#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = S21_SUCCESS;
  if (check_matrix(A)) {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else {
        *result = calc_det(A, A->rows);
      }
    } else {
      status = S21_MATH_OPERATIONS_ERROR;
    }
  } else {
    status = S21_INVALID_MATRIX;
  }
  return status;
}
