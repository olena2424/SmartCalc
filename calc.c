#include "s21_smart_calc.h"

int calc_operator(const char* buff, stack_double* stack_double) {
  int ret = 1;
  long double first = stack_double->data[stack_double->size - 1];
  long double second = stack_double->data[stack_double->size - 2];
  stack_double->size -= 2;
  if (*buff == '+') {
    push_double(stack_double, first + second);
  } else if (*buff == '-') {
    push_double(stack_double, second - first);
  } else if (*buff == '*') {
    push_double(stack_double, second * first);
  } else if (*buff == '/') {
    if (first != 0.0) {
      push_double(stack_double, second / first);
    } else {
      ret = 0;
    }
  } else if (*buff == '^') {
    push_double(stack_double, pow(second, first));
  } else if (*buff == 'm') {
    push_double(stack_double, (int)second % (int)first);
  }
  return ret;
}

void calc_func(const char* buff, stack_double* stack_double) {
  long double elem = stack_double->data[stack_double->size - 1];
  stack_double->size--;
  if (*buff == 'c') {
    push_double(stack_double, cos(elem));
  } else if (*buff == 's') {
    push_double(stack_double, sin(elem));
  } else if (*buff == 't') {
    push_double(stack_double, tan(elem));
  } else if (*buff == 'n') {
    push_double(stack_double, log(elem));
  } else if (*buff == 'l') {
    push_double(stack_double, log10(elem));
  } else if (*buff == 'q') {
    push_double(stack_double, sqrt(elem));
  } else if (*buff == 'z') {
    push_double(stack_double, acos(elem));
  } else if (*buff == 'w') {
    push_double(stack_double, asin(elem));
  } else if (*buff == 'v') {
    push_double(stack_double, atan(elem));
  } else if (*buff == '~') {
    push_double(stack_double, elem * (-1));
  }
}

int is_digit_in_polish(char elem) {
  return ((elem >= '0' && elem <= '9') || elem == '.');
}

int is_min_unary(char elem) { return (elem == '~'); }

int calc(char* polish, long double x, long double* result) {
  int i_polish = 0, i_buff = 0, ret = 1;
  stack_double stack_double = {NULL, 2, 0};
  stack_double.data = malloc(stack_double.capacity * sizeof(long double));
  while (polish[i_polish] != '\0' && ret) {
    char* buff = malloc(sizeof(char) * (strlen(polish) - i_polish));
    while (polish[i_polish] != ' ') {
      buff[i_buff++] = polish[i_polish++];
    }
    buff[i_buff] = '\0';
    if (is_digit_in_polish(buff[0]) ||
        (strlen(buff) > 1 && is_digit_in_polish(buff[1]))) {
      long double num = 0;
      num = strtold(buff, NULL);
      push_double(&stack_double, num);
    } else if (is_operator(buff[0])) {
      ret = calc_operator(buff, &stack_double);
    } else if (is_func_stack(buff[0]) || is_min_unary(buff[0])) {
      calc_func(buff, &stack_double);
    } else if (buff[0] == 'x') {
      push_double(&stack_double, x);
    }
    i_polish++;
    i_buff = 0;
    free(buff);
  }
  *result = stack_double.data[0];
  if (*result != *result) {
    ret = 2;
  }
  free(stack_double.data);
  return ret;
}