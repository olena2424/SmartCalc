# SmartCalc

An implementation of extended version of the standard calculator found in the standard applications of every operating system, using the C programming language and structured programming. In addition to basic arithmetic operations such as add/subtract and multiply/divide, the ability to calculate arithmetic expressions by following the order, as well as some mathematical functions (sine, cosine, logarithm, etc.) was added.
Besides calculating expressions, it also support the use of the x variable and the graphing of the corresponding function.

The project at School 21.

- The program is developed in C language of C11 standard using gcc compiler.
- The program is built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, test, gcov_report.
- The program is developed according to the principles of structured programming.
- Provided full coverage of modules related to calculating expressions with unit-tests using the Check library.
- GUI implementation based on Qt.
- Both integers and real numbers with a dot can be input into the program. 
- The calculation is done after you complete entering the calculating expression and press the `=` symbol.
- Calculating arbitrary bracketed arithmetic expressions in infix notation.
- Calculate arbitrary bracketed arithmetic expressions in infix notation with substitution of the value of the variable _x_ as a number.
- Plotting a graph of a function given by an expression in infix notation with the variable _x_ (with coordinate axes, mark of the used scale and an adaptive grid).
- Domain and codomain of a function are limited to at least numbers from -1000000 to 1000000.
- To plot a graph of a function it is necessary to additionally specify the displayed domain and codomain.
- Accuracy of the fractional part is at least to 7 decimal places.