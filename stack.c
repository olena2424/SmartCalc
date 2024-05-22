#include "s21_smart_calc.h"

void push_char(stack_char* st, char elem) {
  if (st->size >= st->capacity - 1) {
    st->capacity *= 2;
    st->data = realloc(st->data, st->capacity * sizeof(char));
  }
  st->data[st->size] = elem;
  st->size++;
}

void push_double(stack_double* st, long double elem) {
  if (st->size >= st->capacity - 1) {
    st->capacity *= 2;
    st->data = realloc(st->data, st->capacity * sizeof(long double));
  }
  st->data[st->size] = elem;
  st->size++;
}