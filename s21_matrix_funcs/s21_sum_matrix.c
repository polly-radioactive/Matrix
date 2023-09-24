#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = S21_SUCCESS;
  if (check_matrix(A) && check_matrix(B) && result != NULL) {
    if (A->columns == B->columns && A->rows == B->rows) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
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
