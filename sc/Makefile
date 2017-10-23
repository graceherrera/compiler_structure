sc:		sc.l sc.y
			bison -d sc.y
			flex sc.l
			cc -o $@ sc.tab.c lex.yy.c -lfl
