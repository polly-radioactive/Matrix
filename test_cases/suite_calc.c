#include "../s21_test_matrix.h"

START_TEST(calc_1) {
  matrix_t C;
  int result = s21_calc_complements(NULL, &C);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(calc_2) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  int result = s21_calc_complements(&A, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_3) {
  matrix_t A, C, res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  res.matrix[0][0] = 0;
  res.matrix[0][1] = 10;
  res.matrix[0][2] = -20;
  res.matrix[1][0] = 4;
  res.matrix[1][1] = -14;
  res.matrix[1][2] = 8;
  res.matrix[2][0] = -8;
  res.matrix[2][1] = -2;
  res.matrix[2][2] = 4;
  s21_calc_complements(&A, &C);
  int result = s21_eq_matrix(&res, &C);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_4) {
  matrix_t A, C;
  s21_create_matrix(3, 2, &A);
  int result = s21_calc_complements(&A, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_calc(void) {
  Suite *s = suite_create("Checking s21_calc_complements...");
  TCase *tcase = tcase_create("calc_complements");
  tcase_add_test(tcase, calc_1);
  tcase_add_test(tcase, calc_2);
  tcase_add_test(tcase, calc_3);
  tcase_add_test(tcase, calc_4);
  suite_add_tcase(s, tcase);
  return s;
}