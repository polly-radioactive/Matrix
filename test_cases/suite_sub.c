#include "../s21_test_matrix.h"

START_TEST(sub_1) {
  matrix_t B, C;
  s21_create_matrix(3, 3, &B);
  int result = s21_sub_matrix(NULL, &B, &C);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_2) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;

  int result = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sub_3) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);

  int result = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_4) {
  matrix_t A, B, C, check;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 3;
  B.matrix[0][0] = 2;
  check.matrix[0][0] = 1;
  s21_sub_matrix(&A, &B, &C);
  int result = s21_eq_matrix(&C, &check);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_sub(void) {
  Suite *s = suite_create("Checking s21_sub_matrix...");
  TCase *tcase = tcase_create("sub");
  tcase_add_test(tcase, sub_1);
  tcase_add_test(tcase, sub_2);
  tcase_add_test(tcase, sub_3);
  tcase_add_test(tcase, sub_4);
  suite_add_tcase(s, tcase);
  return s;
}
