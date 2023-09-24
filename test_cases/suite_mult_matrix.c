#include "../s21_test_matrix.h"

START_TEST(mult_matrix_1) {
  matrix_t B, C;
  s21_create_matrix(3, 3, &B);
  int result = s21_mult_matrix(NULL, &B, &C);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;

  B.matrix[0][0] = 8;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 2;

  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;

  B.matrix[0][0] = 8;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 2;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  B.matrix[1][2] = 9;

  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A, B, C, res;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 3, &res);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;

  B.matrix[0][0] = 4;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 1;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 5;

  res.matrix[0][0] = 10;
  res.matrix[0][1] = 10;
  res.matrix[0][2] = 10;
  res.matrix[1][0] = 6;
  res.matrix[1][1] = 7;
  res.matrix[1][2] = 7;
  res.matrix[2][0] = 16;
  res.matrix[2][1] = 7;
  res.matrix[2][2] = 7;

  s21_mult_matrix(&B, &A, &C);
  int result = s21_eq_matrix(&C, &res);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_mult_matrix(void) {
  Suite *s = suite_create("Checking s21_mult_matrix...");
  TCase *tcase = tcase_create("mult_matrix");
  tcase_add_test(tcase, mult_matrix_1);
  tcase_add_test(tcase, mult_matrix_2);
  tcase_add_test(tcase, mult_matrix_3);
  tcase_add_test(tcase, mult_matrix_4);
  suite_add_tcase(s, tcase);
  return s;
}
