#include "../s21_test_matrix.h"

START_TEST(eq_1) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_2) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(6, 6, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_3) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  B.matrix[1][2] = 1;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 1;
  B.matrix[2][2] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_4) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  B.matrix[1][2] = 1;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 1;
  B.matrix[2][2] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_5) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0.1234567;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 0.1234566;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_6) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0.12345678;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 0.12345677;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_eq(void) {
  Suite *s = suite_create("Checking s21_eq_matrix...");
  TCase *tcase = tcase_create("eq_matrix");
  tcase_add_test(tcase, eq_1);
  tcase_add_test(tcase, eq_2);
  tcase_add_test(tcase, eq_3);
  tcase_add_test(tcase, eq_4);
  tcase_add_test(tcase, eq_5);
  tcase_add_test(tcase, eq_6);
  suite_add_tcase(s, tcase);
  return s;
}
