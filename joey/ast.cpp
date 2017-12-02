%{
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>
#include <vector>
#define YY_CTX_LOCAL 1
#define YY_CTX_MEMBERS \

int count;
int state;

struct KoreanType {
  std::string koreanChar;
  std::string letterType;
  std::string firstlast;
  KoreanType(const std::string _koreanChar, const std::string _type, const std::string _firstlast) : koreanChar(_koreanChar), letterType(_type), firstlast(_firstlast) {}
};

std::ostream& operator << (std::ostream &out, const std::vector < std::shared_ptr < KoreanType > > &singles) {

	for (auto single : singles) {
		out << single->koreanChar << std::endl;
		out << single->letterType << std::endl;
		out << single->firstlast << std::endl;
		out << "________" << std::endl;
	}
	return out;
}

std::string koreanChar;
std::string letterType;
std::string firstlast;
//#define YYSTYPE std::shared_ptr < KoreanType >
#define YYSTYPE char *
typedef std::vector < std::shared_ptr < KoreanType > > Singles;
Singles singles;

%}
START = STRUCT+ | LINE
STRUCT = (
	LINE {
		std::shared_ptr < KoreanType > single(new KoreanType(koreanChar, letterType, firstlast));
		singles.push_back(single);
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

int main()
{
   yycontext yy;
   memset(&yy, 0, sizeof(yy));
   while (true) {
	   if(yyparse(&yy)) break;
	   std::cout << yyparse(&yy) << std::endl;
   };
   std::cout << singles << std::endl;
   yyrelease(&yy);

   return 0;
}
