#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = S21_SUCCESS;
  if (check_matrix(A)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->columns, A->rows, result);
      if (A->rows != 1) {
        matrix_t C = {0};
        s21_create_matrix(A->rows, A->rows, &C);
        for (int sign = 0, x = 0; x < A->rows; x++) {
          for (int y = 0; y < A->columns; y++) {
            calc_minor(A->matrix, C.matrix, x, y, A->rows);
            if ((x + y) % 2 == 0) {
              sign = 1;
            } else {
              sign = -1;
            }
            result->matrix[x][y] = sign * calc_det(&C, A->rows - 1);
          }
        }

        s21_remove_matrix(&C);
      } else {
        result->matrix[0][0] = 1;
      }
    } else {
      status = S21_MATH_OPERATIONS_ERROR;
    }
  } else {
    status = S21_INVALID_MATRIX;
  }
  return status;
}
