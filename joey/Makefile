CXXFLAGS=-std=gnu++11
all : clean grammar.cpp koreanDat

grammar.cpp : ast.cpp
	leg -o grammar.cpp ast.cpp

koreanDat : grammar.cpp
	g++ grammar.cpp -o koreanDat
	./koreanDat < jamo.dat

clean :
	/bin/rm -rf \#* *~ *.o koreanDat grammar.cpp
