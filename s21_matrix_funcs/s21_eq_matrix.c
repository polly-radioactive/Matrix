#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if (check_matrix(A) && check_matrix(B) && A->columns == B->columns &&
      A->rows == B->rows) {
    if (matrix_check(A, B) == FAILURE) {
      status = FAILURE;
    }
  } else {
    status = FAILURE;
  }
  return status;
}