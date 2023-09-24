#include "../s21_test_matrix.h"

START_TEST(mult_number_1) {
  matrix_t C;
  int result = s21_mult_number(NULL, 2, &C);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 2;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 8;
  s21_mult_number(&A, 2, &C);
  int result = s21_eq_matrix(&C, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t A, C;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int result = s21_mult_number(&A, 2, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s = suite_create("Checking s21_mult_number...");
  TCase *tcase = tcase_create("mult_matrix");
  tcase_add_test(tcase, mult_number_1);
  tcase_add_test(tcase, mult_number_2);
  tcase_add_test(tcase, mult_number_3);
  suite_add_tcase(s, tcase);
  return s;
}