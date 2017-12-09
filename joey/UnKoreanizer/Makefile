CXXFLAGS=-std=gnu++11
all : clean grammar/jamoGrammar.cpp grammar/hangulGrammar.cpp grammar/koreanGrammar.cpp UnKoreanizer

grammar/hangulGrammar.cpp : leg/hangulParser.cpp
	leg -o grammar/hangulGrammar.cpp leg/hangulParser.cpp

grammar/jamoGrammar.cpp : leg/jamoParser.cpp
	leg -o grammar/jamoGrammar.cpp leg/jamoParser.cpp
	
grammar/koreanGrammar.cpp : leg/koreanParser.cpp
	leg -o grammar/koreanGrammar.cpp leg/koreanParser.cpp

UnKoreanizer :
	g++ -o UnKoreanizer UnKoreanizer.cpp
	./UnKoreanizer < dat/korean.dat

clean :
	/bin/rm -rf \#* *~ *.o UnKoreanizer grammar/*
