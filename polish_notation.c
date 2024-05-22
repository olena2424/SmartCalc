#include "s21_smart_calc.h"

int is_digit(char elem) {
  return ((elem >= '0' && elem <= '9') || elem == 'x' || elem == '.');
}

int is_func(char elem) {
  return (elem == 'c' || elem == 's' || elem == 't' || elem == 'a' ||
          elem == 'l');
}

char add_func(const char* input, int* i_input) {
  char ret = -1;
  if (input[*i_input] == 'c' && input[(*i_input) + 1] == 'o' &&
      input[(*i_input) + 2] == 's') {
    ret = 'c';
    *i_input += 3;
  } else if (input[*i_input] == 't' && input[(*i_input) + 1] == 'a' &&
             input[(*i_input) + 2] == 'n') {
    ret = 't';
    *i_input += 3;
  } else if (input[*i_input] == 's') {
    if (input[(*i_input) + 1] == 'i' && input[(*i_input) + 2] == 'n') {
      ret = 's';
      *i_input += 3;
    } else if (input[(*i_input) + 1] == 'q' && input[(*i_input) + 2] == 'r' &&
               input[(*i_input) + 3] == 't') {
      ret = 'q';
      *i_input += 4;
    }
  } else if (input[*i_input] == 'l') {
    if (input[(*i_input) + 1] == 'n') {
      ret = 'n';
      *i_input += 2;
    } else if (input[(*i_input) + 1] == 'o' && input[(*i_input) + 2] == 'g') {
      ret = 'l';
      *i_input += 3;
    }
  } else if (input[*i_input] == 'a') {
    if (input[(*i_input) + 1] == 'c' && input[(*i_input) + 2] == 'o' &&
        input[(*i_input) + 3] == 's') {
      ret = 'z';
    } else if (input[(*i_input) + 1] == 's' && input[(*i_input) + 2] == 'i' &&
               input[(*i_input) + 3] == 'n') {
      ret = 'w';
    } else if (input[(*i_input) + 1] == 't' && input[(*i_input) + 2] == 'a' &&
               input[(*i_input) + 3] == 'n') {
      ret = 'v';
    }
    *i_input += 4;
  }
  return ret;
}

int is_operator(char elem) {
  return (elem == '+' || elem == '-' || elem == '*' || elem == '/' ||
          elem == '^' || elem == 'm');
}

int is_unary(const char* input, int i_input) {
  int ret = 0;
  if (input[i_input] == '-' || input[i_input] == '+') {
    if (i_input > 0 && is_operator(input[i_input - 1])) {
      ret = 2;
    } else if (i_input == 0 || (i_input > 0 && !is_digit(input[i_input - 1]) &&
                                input[i_input - 1] != ')')) {
      ret = 1;
    }
  } else {
    if (i_input == 0 || (i_input > 0 && (is_operator(input[i_input - 1])))) {
      ret = 2;
    }
  }
  return ret;
}

int priority(char elem) {
  int ret = 0;
  if (elem == '+' || elem == '-')
    ret = 1;
  else if (elem == '*' || elem == '/' || elem == 'm')
    ret = 2;
  else if (elem == '^')
    ret = 3;
  else if (elem == '~')
    ret = 4;
  return ret;
}

int is_func_stack(char elem) {
  return (elem == 'c' || elem == 's' || elem == 't' || elem == 'n' ||
          elem == 'l' || elem == 'q' || elem == 'z' || elem == 'w' ||
          elem == 'v');
}

int check_mod(const char* input, int i_input) {
  return (input[i_input + 1] == 'o' && input[i_input + 2] == 'd') ? 0 : 1;
}

void from_stack_to_polish(char* polish_not, int* i_polish_not,
                          stack_char* stack_char) {
  polish_not[(*i_polish_not)++] = stack_char->data[stack_char->size - 1];
  stack_char->data[stack_char->size - 1] = '\0';
  stack_char->size--;
  polish_not[(*i_polish_not)++] = ' ';
}

void add_digit(const char* input, int* i_input, int* ret, char* polish_not,
               int* i_polish_not) {
  int cnt_dot = 0;
  while (is_digit(input[*i_input])) {
    if (input[*i_input] == '.') {
      cnt_dot++;
    }
    if (*i_input > 0 && input[*i_input] == 'x' && input[*i_input - 1] == 'x') {
      *ret = 1;
    }
    polish_not[(*i_polish_not)++] = input[(*i_input)++];
  }
  if (cnt_dot > 1) {  // если точек больше 1
    *ret = 1;
  }
  if (*ret == 0) {  // пробелы
    polish_not[(*i_polish_not)++] = ' ';
  }
}

void add_operator(const char* input, int* i_input, int* ret, char* polish_not,
                  int* i_polish_not, stack_char* stack_char) {
  int un = is_unary(input, *i_input);  // 0 - bin; 1 - un; 2 - err
  if (un != 2) {
    if (input[*i_input] == 'm') {
      *ret = check_mod(input, *i_input);
    }
    while (*ret == 0 && stack_char->size > 0 &&
           priority(stack_char->data[stack_char->size - 1]) >=
               priority(input[*i_input])) {
      from_stack_to_polish(polish_not, i_polish_not, stack_char);
    }
    if (un == 1) {
      if (input[*i_input] == '-') {
        push_char(stack_char, '~');
      }
    } else {
      push_char(stack_char, input[*i_input]);
    }
    if (input[*i_input] == 'm') {
      (*i_input) += 2;
    }
    (*i_input)++;
  } else {  // error
    *ret = 1;
  }
}

void add_closing_bracket(int* ret, char* polish_not, int* i_polish_not,
                         stack_char* stack_char) {
  if (stack_char->size > 0) {
    while (*ret == 0 && stack_char->data[stack_char->size - 1] != '(') {
      from_stack_to_polish(polish_not, i_polish_not, stack_char);
      if (stack_char->size == 0) {
        *ret = 1;
      }
    }
  } else {
    *ret = 1;
  }
  if (*ret == 0) {
    stack_char->data[stack_char->size - 1] = '\0';
    stack_char->size--;
  }
  if (stack_char->size > 0 &&
      is_func_stack(stack_char->data[stack_char->size - 1])) {
    from_stack_to_polish(polish_not, i_polish_not, stack_char);
  }
}

int conversion(const char* input, char* polish_not) {
  int i_input = 0, i_polish_not = 0, ret = 0;
  stack_char stack_char = {NULL, 2, 0};
  stack_char.data = malloc(stack_char.capacity * sizeof(char));
  if (is_operator(input[strlen(input) - 1])) {
    ret = 1;
  }
  while (input[i_input] != '\0' && ret == 0) {
    if (is_digit(input[i_input])) {  // число, заносим в вывод
      add_digit(input, &i_input, &ret, polish_not, &i_polish_not);
    } else if (input[i_input] == '(') {
      push_char(&stack_char, input[i_input]);
      i_input++;
    } else if (is_func(input[i_input])) {
      char ans = add_func(input, &i_input);
      if (ans != -1 && input[i_input + 1] != ')' && input[i_input] == '(' &&
          !(is_operator(input[i_input + 1]) && input[i_input + 2] == ')')) {
        push_char(&stack_char, ans);
      } else {
        ret = 1;
      }
    } else if (is_operator(input[i_input])) {
      add_operator(input, &i_input, &ret, polish_not, &i_polish_not,
                   &stack_char);
    } else if (input[i_input] == ')') {
      add_closing_bracket(&ret, polish_not, &i_polish_not, &stack_char);
      i_input++;
    } else if (input[i_input] == ' ') {
      i_input++;
    } else {
      ret = 1;
    }
  }
  while (stack_char.size > 0 && ret == 0) {
    if (stack_char.data[stack_char.size - 1] == '(') {
      ret = 1;
    } else {
      from_stack_to_polish(polish_not, &i_polish_not, &stack_char);
    }
  }
  polish_not[i_polish_not] = '\0';
  if (strlen(polish_not) == 0 || !is_digit(polish_not[0])) {
    ret = 1;
  }
  free(stack_char.data);
  return ret;
}
