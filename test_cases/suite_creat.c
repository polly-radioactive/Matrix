#include "../s21_test_matrix.h"

START_TEST(creat_1) {
  matrix_t A;
  int result = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(creat_2) {
  matrix_t A;
  int result = s21_create_matrix(-2, 3, &A);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(creat_3) {
  matrix_t A;
  int result = s21_create_matrix(-3, 2, &A);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(creat_4) {
  matrix_t A;
  int result = s21_create_matrix(0, 2, &A);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(creat_5) {
  matrix_t A;
  int result = s21_create_matrix(3, 0, &A);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *suite_creat(void) {
  Suite *s = suite_create("Checking s21_create_matrix...");
  TCase *tcase = tcase_create("create_matrix");
  tcase_add_test(tcase, creat_1);
  tcase_add_test(tcase, creat_2);
  tcase_add_test(tcase, creat_3);
  tcase_add_test(tcase, creat_4);
  tcase_add_test(tcase, creat_5);
  suite_add_tcase(s, tcase);
  return s;
}