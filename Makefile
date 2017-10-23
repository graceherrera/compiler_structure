simplest_calc:	calc_scanner.l	simplest_calc.y
								bison -d simplest_calc.y
								flex calc_scanner.l
								cc -o $@ simplest_calc.tab.c lex.yy.c -lfl
