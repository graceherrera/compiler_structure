%{
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>
#include <vector>
#define YY_CTX_LOCAL 
#define YY_CTX_MEMBERS \

//int count;
//int state;

struct KoreanJamoType {
  std::string koreanChar;
  std::string letterType;
  std::string firstlast;
  KoreanJamoType(const std::string _koreanChar, const std::string _type, const std::string _firstlast) : koreanChar(_koreanChar), letterType(_type), firstlast(_firstlast) {}
};

std::ostream& operator << (std::ostream &out, const std::vector < std::shared_ptr < KoreanJamoType > > &jamos) {

	for (auto jamo : jamos) {
		out << jamo->koreanChar << std::endl;
		out << jamo->letterType << std::endl;
		out << jamo->firstlast << std::endl;
		out << "________" << std::endl;
	}
	return out;
}

std::string koreanChar;
std::string letterType;
std::string firstlast;
//#define YYSTYPE std::shared_ptr < KoreanJamoType >
#define YYSTYPE char *
typedef std::vector < std::shared_ptr < KoreanJamoType > > Jamos;
Jamos jamos;

%}
START = STRUCT+ | LINE
STRUCT = (
	LINE {
		std::shared_ptr < KoreanJamoType > jamo(new KoreanJamoType(koreanChar, letterType, firstlast));
		jamos.push_back(jamo);
		koreanChar = "";
		letterType = "";
		firstlast = "";
	}
)
LINE = (
	<a:TOKEN> SP {
	koreanChar = yytext;
	} 
	<b:TOKEN> SP { 
		letterType = yytext;
		} 
	<c:TOKEN> (EOL | EOL EOF) {
		firstlast = yytext;
		}
)

TOKEN = ( [\x3131-ㆎ]+ | [ㅏ-ㅣ]+ | [a-z\-|~]+)
SP = [ ]
EOL = [\n]
EOF = !. { std::cout << "END OF FILE" << std::endl; }
%%

void startJamo() {
   yycontext yy;
   memset(&yy, 0, sizeof(yy));
   while (true) {
	   if(yyparse(&yy)) break;
	   std::cout << yyparse(&yy) << std::endl;
   };
   std::cout << "JAMO COUNT: ";
   std::cout << jamos.size() << std::endl;
   yyrelease(&yy);
}
