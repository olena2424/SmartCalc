CC=gcc
FLAGS=-Werror -Wextra -Wall -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
	LIBS = -lcheck -lrt -lpthread -lm -lsubunit  
else
	LIBS = -lcheck
endif

all: install

install:
	mkdir build
	qmake6 SmartCalc.pro -o build 
	cd build && make && cd ../

run: 
	./build/SmartCalc

dvi:
	doxygen Doxyfile
#open doxygen/html/index.html

dist:
	tar -czf build.tar.gz --directory=build/ .

test: 
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage stack.c calc.c polish_notation.c calc_tests.c -o test $(LIBS)
	./test

gcov_report: test
	lcov -t "test_s21_calc" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno

clean:
	rm -f test
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
	rm -rf report
	rm -rf doxygen
	rm -f build.tar.gz

uninstall:
	rm -rf build
	make clean
