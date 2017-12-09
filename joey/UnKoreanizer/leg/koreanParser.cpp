%{
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>
#include <vector>
#define YY_CTX_LOCAL 
#define YY_CTX_MEMBERS \

struct KoreanJamoType {
  std::string koreanChar;
  std::string letterType;
  std::string firstlast;
  std::string begining;
  std::string end;
  KoreanJamoType(const std::string _koreanChar, const std::string _type, const std::string _firstlast) : koreanChar(_koreanChar), letterType(_type), firstlast(_firstlast) {}
  KoreanJamoType(const std::string _koreanChar, const std::string _type, const std::string _begining, const std::string _end, const std::string _firstlast) : koreanChar(_koreanChar), letterType(_type), begining(_begining), end(_end), firstlast(_firstlast) {}
};

struct KoreanCompoundType {
  //typedef std::vector < std::shared_ptr < KoreanJamoType > > Jamos;
  std::string compoundChar;
  std::shared_ptr < KoreanJamoType > initial;
  std::shared_ptr < KoreanJamoType > middle;
  std::shared_ptr < KoreanJamoType > last;
  KoreanCompoundType(const std::string _compoundChar, const  std::shared_ptr < KoreanJamoType > _initial, const std::shared_ptr < KoreanJamoType > _middle, const std::shared_ptr < KoreanJamoType > _last) : compoundChar(_compoundChar), initial(_initial), middle(_middle), last(_last) {}
  KoreanCompoundType(const std::string _compoundChar, const  std::shared_ptr < KoreanJamoType > _initial, const std::shared_ptr < KoreanJamoType > _middle) : compoundChar(_compoundChar), initial(_initial), middle(_middle) {}
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

std::ostream& operator << (std::ostream &out, const std::vector < std::shared_ptr < KoreanCompoundType > > &compounds) {

	for (auto compound : compounds) {
		out << compound->compoundChar << std::endl;
		out << compound->initial->koreanChar << " " << compound->middle->koreanChar;
		
		if(compound->last) {
			out << " " << compound->last->koreanChar;
		}
		out << std::endl;
		
		out << compound->initial->begining << compound->middle->firstlast;
		if(compound->last) {
			out << compound->last->end << " ";
		}
		out << std::endl;
		out << "________" << std::endl;
	}
	return out;
}



std::string koreanChar;
std::string letterType;
std::string firstlast;
std::string begining;
std::string end;

std::string compound;
std::shared_ptr < KoreanJamoType > initial;
std::shared_ptr < KoreanJamoType > middle;
std::shared_ptr < KoreanJamoType > last;

#define YYSTYPE char *
typedef std::vector < std::shared_ptr < KoreanJamoType > > Jamos;
Jamos jamos;
typedef std::vector < std::shared_ptr < KoreanCompoundType > > Compounds;
Compounds compounds;

std::shared_ptr < KoreanJamoType > getJamo(char *target) {
	for(int i = 0; i < jamos.size(); i++) {
		if(jamos[i]->koreanChar == target) {
			return jamos[i];
		}
	}
	std::cout << "INVALID JAMO PARSE: " << target << std::endl;
}

%}
START = (CSTRUCT+ | STRUCT+)+
CSTRUCT = (
	<TITLE> {
		//last = "";
		std::shared_ptr < KoreanCompoundType > title(new KoreanCompoundType(compound, initial, middle));
		compounds.push_back(title);
		//compound = "";
		//initial = "";
	}
	| <SET> {
		
		std::shared_ptr < KoreanCompoundType > set(new KoreanCompoundType(compound, initial, middle, last));
		compounds.push_back(set);
		//compound = "";
		//initial = "";
		//last = "";
	}
)
STRUCT = (
	LINE {
		std::shared_ptr < KoreanJamoType > jamo(new KoreanJamoType(koreanChar, letterType, begining, end, firstlast));
		jamos.push_back(jamo);
		koreanChar = "";
		letterType = "";
		firstlast = "";
		begining = "";
		end = "";
	}
)
TITLE = (
	<a:TOKEN_HANGUL> SP {
		compound = yytext;
	}
	<b:TOKEN_JAMO> SP {
		//initial = yytext;
		initial = getJamo(yytext);
	}
	<c:TOKEN_JAMO> SP EOL{
		//middle = yytext;
		middle = getJamo(yytext);
	}
)
SET = (
	<a:TOKEN_HANGUL> SP {
		compound = yytext;
	}
	<b:TOKEN_JAMO> SP {
		//initial = yytext;
		initial = getJamo(yytext);
	}
	<c:TOKEN_JAMO> SP {
		//middle = yytext;
		middle = getJamo(yytext);
	}
	<d:TOKEN_JAMO> SP EOL {
		//last = yytext;
		last = getJamo(yytext);
	}
)
LINE = (
	<a:TOKEN> SP {
		koreanChar = yytext;
	} 
	<b:TOKEN> SP { 
		letterType = yytext;
	} 
	<c:TOKEN> (EOL) {
		firstlast = yytext;
		int i = 0;
		while(i < firstlast.length() && firstlast[i] != '|') {
			begining += firstlast[i];
			i++;
		}
		i++;
		if(i < firstlast.length()) {
			while(i < firstlast.length()) {
				end += firstlast[i];
				i++;
			}
		}
	}
)
TOKEN_HANGUL = ([가-힢]+) {}
TOKEN_JAMO = ([\x3131-ㆎ]+) {}
TOKEN = ( [\x3131-ㆎ]+ | [ㅏ-ㅣ]+ | [a-z\-|~]+) {}
SP = [ ]
EOL = [\n]
EOF = !. {}
%%

void startParser() {
   yycontext yy;
   memset(&yy, 0, sizeof(yy));
   while (true) {
	   if(yyparse(&yy)) break;
	   std::cout << yyparse(&yy) << std::endl;
   };
   yyrelease(&yy);
}
