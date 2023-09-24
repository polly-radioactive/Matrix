#include "../s21_test_matrix.h"

START_TEST(inverse_1) {
  matrix_t C;
  int result = s21_inverse_matrix(NULL, &C);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  int result = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t A, C;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  int result = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_4) {
  matrix_t A, C, res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  res.matrix[0][0] = 1;
  res.matrix[0][1] = -1;
  res.matrix[0][2] = 1;
  res.matrix[1][0] = -38;
  res.matrix[1][1] = 41;
  res.matrix[1][2] = -34;
  res.matrix[2][0] = 27;
  res.matrix[2][1] = -29;
  res.matrix[2][2] = 24;
  s21_inverse_matrix(&A, &C);
  int result = s21_eq_matrix(&res, &C);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_inverse(void) {
  Suite *s = suite_create("Checking s21_inverse_matrix...");
  TCase *tcase = tcase_create("inverse_matrix");
  tcase_add_test(tcase, inverse_1);
  tcase_add_test(tcase, inverse_2);
  tcase_add_test(tcase, inverse_3);
  tcase_add_test(tcase, inverse_4);
  suite_add_tcase(s, tcase);
  return s;
}