#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = S21_SUCCESS;
  if (check_matrix(A) && check_matrix(B) && result != NULL) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      status = S21_MATH_OPERATIONS_ERROR;
    }
  } else {
    status = S21_INVALID_MATRIX;
  }
  return status;
}