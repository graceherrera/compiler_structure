%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#define YY_CTX_LOCAL 1
#define YY_CTX_MEMBERS \

struct KoreanCompoundType {
  std::string compoundChar;
  std::string initial;
  std::string middle;
  std::string last;
  KoreanCompoundType(const std::string _compoundChar, const std::string _initial, const std::string _middle, const std::string _last) : compoundChar(_compoundChar), initial(_initial), middle(_middle), last(_last) {}
};

std::ostream& operator << (std::ostream &out, const std::vector < std::shared_ptr < KoreanCompoundType > > &compounds) {
	for (auto compound : compounds) {
		out << compound->compoundChar << std::endl;
		out << compound->initial << " " << compound->middle << " " << compound->last <<  std::endl;
		out << "________" << std::endl;
	}
	return out;
}
typedef std::vector < std::shared_ptr < KoreanCompoundType > > Compounds;
Compounds compounds;
#define YYSTYPE char *
std::string compound;
std::string initial;
std::string middle;
std::string last;
%}
START = STRUCT+ | TITLE | SET
STRUCT = (
	<TITLE> {
		last = "";
		std::shared_ptr < KoreanCompoundType > title(new KoreanCompoundType(compound, initial, middle, last));
		compounds.push_back(title);
		compound = "";
		initial = "";
	}
	| <SET> {
		std::shared_ptr < KoreanCompoundType > set(new KoreanCompoundType(compound, initial, middle, last));
		compounds.push_back(set);
		compound = "";
		initial = "";
		last = "";
	}
)
TITLE = (
	<a:TOKEN_HANGUL> SP {
		compound = yytext;
	}
	<b:TOKEN_JAMO> SP {
		initial = yytext;
	}
	<c:TOKEN_JAMO> SP EOL{
		middle = yytext;
	}
)
SET = (
	<a:TOKEN_HANGUL> SP {
		compound = yytext;
	}
	<b:TOKEN_JAMO> SP {
		initial = yytext;
	}
	<c:TOKEN_JAMO> SP {
		middle = yytext;
	}
	<d:TOKEN_JAMO> SP EOL {
		last = yytext;
	}
)
TOKEN_HANGUL = ([가-힢]+)
TOKEN_JAMO = ([\x3131-ㆎ]+)
SP = [ ]
EOL = [\n]
EOF = !.
%%

void startHangulParser() {
   yycontext yy;
   memset(&yy, 0, sizeof(yy));
   while (true) {
	   if(yyparse(&yy)) break;
   };
   std::cout << "Hangul Count: ";
   std::cout << compounds.size() << std::endl;
   yyrelease(&yy);
}
