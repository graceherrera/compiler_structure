/* http://memory.loc.gov/diglib/codetables/9.3.html */
/* Korean Unicode character list */

%{
#include <stdio.h>
%}
/* definitions */

%%

"ㄲ"|"ㄴ"|"ㄷ"|"ㄹ"|"ㅁ"|"ㅂ"|"ㅅ"       printf(" You've entered a Korean consonant: %s\n", yytext );
"ㅇ"|"ㅈ"|"ㅊ"|"ㅋ"|"ㅌ"|"ㅍ"|"ㅎ"|"ㄸ"       printf(" You've entered a Korean consonant: %s\n", yytext );
"ㅃ"|"ㅆ"|"ㅉ"       printf(" You've entered a Korean consonant: %s\n", yytext );

"ㄱ"       printf(" The Korean consonant %s has the sound k/g\n", yytext );

"ㅏ"|"ㅐ"|"ㅑ"|"ㅓ"|"ㅔ"|"ㅕ"|"ㅗ"|"ㅘ"       printf(" You've entered a Korean vowel: %s\n", yytext );
"ㅛ"|"ㅜ"|"ㅠ"|"ㅡ"|"ㅢ"|"ㅣ"      printf(" You've entered a Korean vowel: %s\n", yytext );


"{"[^}\n]*"}"     /* eat up one-line comments */

[ \t\n]+          /* eat up whitespace */

.           printf( "Unrecognized character: %s\n", yytext );

%%

main()
{
yylex();
}
