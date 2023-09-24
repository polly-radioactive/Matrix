#include "../s21_test_matrix.h"

START_TEST(trans_1) {
  matrix_t C;
  int result = s21_transpose(NULL, &C);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(trans_2) {
  matrix_t A, C;
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  int result = s21_transpose(&A, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(trans_3) {
  matrix_t A, res, C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &res);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  res.matrix[0][0] = 1;
  res.matrix[0][1] = 4;
  res.matrix[1][0] = 2;
  res.matrix[1][1] = 5;
  res.matrix[2][0] = 3;
  res.matrix[2][1] = 6;

  s21_transpose(&A, &C);
  int result = s21_eq_matrix(&C, &res);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_trans(void) {
  Suite *s = suite_create("Checking s21_transpose...");
  TCase *tcase = tcase_create("transpose");
  tcase_add_test(tcase, trans_1);
  tcase_add_test(tcase, trans_2);
  tcase_add_test(tcase, trans_3);
  suite_add_tcase(s, tcase);
  return s;
}