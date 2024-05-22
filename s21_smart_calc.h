/**
 * @mainpage
 * The Smart Calculator v1.0 developed in C language, GUI implementation
 *  based on Qt with qcustomplot.h usage for graphics
 *
 * Calculating arbitrary bracketed arithmetic expressions in infix notation.
 *
 * Calculate arbitrary bracketed arithmetic expressions in infix notation with
 * substitution of the value of the variable x as a number.
 *
 * Plotting a graph of a function given by an expression in infix notation with
 * the variable x (with coordinate axes, mark of the used scale and an adaptive
 * grid)
 *
 * Supports such operations as brackets, addition, subtraction, multiplication,
 * division, power, nodulus, unary plus, unary minus.
 * Also supports functions: cos(x), sin(x), tan(x), acos(x), asin(x), atan(x),
 * sqrt(x), ln(x), log(x)
 *
 */

#ifndef S21_SMART_CALC
#define S21_SMART_CALC

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @class stack_char
 *
 * @brief Realization of stack of chars
 */
typedef struct {
  char* data;
  int capacity;
  int size;
} stack_char;

/**
 * @class stack_double
 *
 * @brief Realization of stack of doubles
 */
typedef struct {
  long double* data;
  int capacity;
  int size;
} stack_double;

void push_char(stack_char* st, char elem);
void push_double(stack_double* st, long double elem);

int is_digit(char elem);
int is_func(char elem);
char add_func(const char* input, int* i_input);
int is_operator(char elem);
int is_unary(const char* input, int i_input);
int priority(char elem);
int is_func_stack(char elem);
int check_mod(const char* input, int i_input);
void from_stack_to_polish(char* polish_not, int* i_polish_not,
                          stack_char* stack_char);
void add_digit(const char* input, int* i_input, int* ret, char* polish_not,
               int* i_polish_not);
void add_operator(const char* input, int* i_input, int* ret, char* polish_not,
                  int* i_polish_not, stack_char* stack_char);
void add_closing_bracket(int* ret, char* polish_not, int* i_polish_not,
                         stack_char* stack_char);
int conversion(const char* input, char* polish_not);

int calc_operator(const char* buff, stack_double* stack_double);
void calc_func(const char* buff, stack_double* stack_double);
int is_digit_in_polish(char elem);
int is_min_unary(char elem);
int calc(char* polish, long double x, long double* result);

#endif