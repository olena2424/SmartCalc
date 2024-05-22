#include "calc_tests.h"

START_TEST(calc_test_1) {
  char* input = "15.3+2.8";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 18.1;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_2) {
  char* input = "15.3-2";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 13.3;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_3) {
  char* input = "2.5*2";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 5;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_4) {
  char* input = "15.6/3";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 5.2;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_5) {
  char* input = "17 mod 3";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 2;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_6) {
  char* input = "2^8";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 256;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_7) {
  char* input = "cos(1)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 0.5403023058;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_8) {
  char* input = "sin(1)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 0.8414709848;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_9) {
  char* input = "tan(1)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 1.5574077246;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_10) {
  char* input = "atan(1)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 0.7853981633;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_11) {
  char* input = "asin(1)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 1.5707963267;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_12) {
  char* input = "acos(1)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 0;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_13) {
  char* input = "sqrt(4)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 2;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_14) {
  char* input = "ln(5)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 1.6094379124;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_15) {
  char* input = "log(5)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  conversion(input, polish);
  long double result_num = 0.0;
  calc(polish, 1, &result_num);
  long double ans = 0.6989700043;
  ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
  free(polish);
}
END_TEST

START_TEST(calc_test_16) {
  char* input = "log(";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  ck_assert_int_eq(result, 1);
  free(polish);
}
END_TEST

START_TEST(calc_test_17) {
  char* input = "1/0";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  conversion(input, polish);
  long double result_num = 0.0;
  int calc_res = calc(polish, 1, &result_num);
  ck_assert_int_eq(calc_res, 0);
  free(polish);
}
END_TEST

START_TEST(calc_test_18) {
  char* input = "sqrt(-2)";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  conversion(input, polish);
  long double result_num = 0.0;
  int calc_res = calc(polish, 1, &result_num);
  ck_assert_int_eq(calc_res, 2);
  free(polish);
}
END_TEST

START_TEST(calc_test_19) {
  char* input = "40+";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  ck_assert_int_eq(result, 1);
  free(polish);
}
END_TEST

START_TEST(calc_test_20) {
  char* input = "2-*3";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  ck_assert_int_eq(result, 1);
  free(polish);
}
END_TEST

START_TEST(calc_test_21) {
  char* input = "*3+2";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  ck_assert_int_eq(result, 1);
  free(polish);
}
END_TEST

START_TEST(calc_test_22) {
  char* input =
      "ln(sqrt((log((sqrt(5233332.555)*log(3876.8768))/"
      "(log(107.578-0078.0785))-(log((70784.78/(50782.807-ln(123.432)/"
      "ln(4762.213))+ln(4321.67)))/"
      "(ln(13433.42)-((532.2253*sqrt(1523.5523))+5230.3255)))*123456.12346))))";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  if (result != 1) {
    long double result_num = 0.0;
    int calc_res = calc(polish, 1, &result_num);
    if (calc_res == 1) {
      long double ans = 0.66053149;
      ck_assert_ldouble_eq_tol(result_num, ans, 1e-7);
    }
  }
  free(polish);
}
END_TEST

START_TEST(calc_test_23) {
  char* input = "2-+2";
  char* polish = malloc(sizeof(char) * 2 * strlen(input) + 1);
  int result = conversion(input, polish);
  ck_assert_int_eq(result, 1);
  free(polish);
}
END_TEST

Suite* calc_suite() {
  Suite* suite = suite_create("calc");
  TCase* tc_core = tcase_create("calc_case");

  tcase_add_test(tc_core, calc_test_1);
  tcase_add_test(tc_core, calc_test_2);
  tcase_add_test(tc_core, calc_test_3);
  tcase_add_test(tc_core, calc_test_4);
  tcase_add_test(tc_core, calc_test_5);
  tcase_add_test(tc_core, calc_test_6);
  tcase_add_test(tc_core, calc_test_7);
  tcase_add_test(tc_core, calc_test_8);
  tcase_add_test(tc_core, calc_test_9);
  tcase_add_test(tc_core, calc_test_10);
  tcase_add_test(tc_core, calc_test_11);
  tcase_add_test(tc_core, calc_test_12);
  tcase_add_test(tc_core, calc_test_13);
  tcase_add_test(tc_core, calc_test_14);
  tcase_add_test(tc_core, calc_test_15);
  tcase_add_test(tc_core, calc_test_16);
  tcase_add_test(tc_core, calc_test_17);
  tcase_add_test(tc_core, calc_test_18);
  tcase_add_test(tc_core, calc_test_19);
  tcase_add_test(tc_core, calc_test_20);
  tcase_add_test(tc_core, calc_test_21);
  tcase_add_test(tc_core, calc_test_22);
  tcase_add_test(tc_core, calc_test_23);
  suite_add_tcase(suite, tc_core);

  return suite;
}

void run_testcase(Suite* testcase) {
  SRunner* sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

int main() {
  Suite* list_cases[] = {calc_suite(), NULL};
  for (Suite** current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
  return 0;
}