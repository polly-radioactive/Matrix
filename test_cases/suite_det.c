#include "../s21_test_matrix.h"

START_TEST(det_1) {
  double C;
  int result = s21_determinant(NULL, &C);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(det_2) {
  matrix_t A;
  double C;
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
  int result = s21_determinant(&A, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_3) {
  matrix_t A;
  double C;
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
  s21_determinant(&A, &C);
  ck_assert_int_eq(C, -40);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_4) {
  matrix_t A;
  double C;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  s21_determinant(&A, &C);
  ck_assert_int_eq(C, 4);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_5) {
  matrix_t A;
  double C;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 9;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 6;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 2;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 4;
  s21_determinant(&A, &C);
  ck_assert_int_eq(C, 200);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_6) {
  matrix_t A;
  double C;
  s21_create_matrix(3, 2, &A);
  int result = s21_determinant(&A, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_det(void) {
  Suite *s = suite_create("Checking s21_determinant...");
  TCase *tcase = tcase_create("determinant");
  tcase_add_test(tcase, det_1);
  tcase_add_test(tcase, det_2);
  tcase_add_test(tcase, det_3);
  tcase_add_test(tcase, det_4);
  tcase_add_test(tcase, det_5);
  tcase_add_test(tcase, det_6);
  suite_add_tcase(s, tcase);
  return s;
}