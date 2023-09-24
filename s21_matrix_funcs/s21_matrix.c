#include "../s21_matrix.h"

int check_matrix(matrix_t *A) {
  int status = SUCCESS;
  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    status = FAILURE;
  }
  return status;
}

int matrix_check(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((A->matrix[i][j] - B->matrix[i][j] > eps) ||
          (B->matrix[i][j] - A->matrix[i][j] > eps)) {
        status = FAILURE;
      }
    }
  }
  return status;
}

// int minor_i(matrix_t *A, int rows_m, int columns_m, matrix_t *C) {
//   int status = S21_SUCCESS;
//   if (check_matrix(A) && !check_matrix(C)) {
//     s21_create_matrix(A->columns - 1, A->rows - 1, C);
//     for (int i = 0, x = 0; i < A->rows; i++) {
//       for (int j = 0, y = 0; j < A->columns; j++) {
//         if (i != rows_m && j != columns_m) {
//           C->matrix[x][y] = A->matrix[i][j];
//           y++;
//         }
//       }
//       if (i != rows_m) {
//         x++;
//       }
//     }
//   } else {
//     status = S21_INVALID_MATRIX;
//   }
//   return status;
// }

// int algebraic_addition(int rows_m, int columns_m) {
//   int tmp = pow(-1, rows_m + columns_m);
//   return tmp;
// }

// double square_determinant(matrix_t *A) {
//   double result =
//       A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
//   return result;
// }

// int print_matrix(matrix_t *A) {
//   if ((A->rows == 0) || (A->columns == 0)) {
//     printf("empty_matrix\n");
//   } else {
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         printf("%f\t", A->matrix[i][j]);
//       }
//       printf("\n");
//     }
//   }
//   return 0;
// }

void calc_minor(double **A, double **C, int rows_m, int columns_m, int size) {
  for (int row = 0, x = 0; row < size; row += 1) {
    for (int col = 0, y = 0; col < size; col += 1) {
      if (row != rows_m && col != columns_m) {
        C[x][y++] = A[row][col];
        if (y == size - 1) {
          y = 0;
          x++;
        }
      }
    }
  }
}

double calc_det(matrix_t *A, int size) {
  if (size == 1) return A->matrix[0][0];
  matrix_t C = {0};
  double result = 0;
  s21_create_matrix(size, size, &C);
  for (int sign = 1, x = 0; x < size; x += 1, sign *= (-1)) {
    calc_minor(A->matrix, C.matrix, 0, x, size);
    result += sign * A->matrix[0][x] * calc_det(&C, size - 1);
  }
  s21_remove_matrix(&C);
  return result;
}