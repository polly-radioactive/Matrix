#include "s21_test_matrix.h"

int main(void) {
  int total = 10;
  Suite *test_cases[10];
  test_cases[0] = suite_creat();
  test_cases[1] = suite_eq();
  test_cases[2] = suite_sum();
  test_cases[3] = suite_sub();
  test_cases[4] = suite_mult_number();
  test_cases[5] = suite_mult_matrix();
  test_cases[6] = suite_trans();
  test_cases[7] = suite_calc();
  test_cases[8] = suite_det();
  test_cases[9] = suite_inverse();

  for (int i = 0; i < total; i++) {
    SRunner *runner = srunner_create(test_cases[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }
}
