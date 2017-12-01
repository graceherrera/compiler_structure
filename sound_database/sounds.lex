%{
#include <stdio.h>
%}
/* definitions */

/*consonants & vowels*/
%%

"ㄲ"         printf("sound for %s is: k/t", yytext);
"ㄱ"         printf("sound for %s is: g", yytext);
"ㄴ"         printf("sound for %s is: n", yytext);
"ㄷ"         printf("sound for %s is: d", yytext);
"ㄹ"         printf("sound for %s is: r/l", yytext);
"ㅁ"         printf("sound for %s is: m", yytext);
"ㅂ"         printf("sound for %s is: b", yytext);
"ㅅ"         printf("sound for %s is: s", yytext);
"ㅇ"         printf("sound for %s is: -/ng", yytext);
"ㅈ"         printf("sound for %s is: j", yytext);
"ㅊ"         printf("sound for %s is: ch", yytext);
"ㅋ"         printf("sound for %s is: k", yytext);
"ㅌ"         printf("sound for %s is: t", yytext);
"ㅍ"         printf("sound for %s is: p", yytext);
"ㅎ"         printf("sound for %s is: h", yytext);
"ㄸ"         printf("sound for %s is: tt", yytext);
"ㅃ"         printf("sound for %s is: bb", yytext);
"ㅆ"         printf("sound for %s is: ss", yytext);
"ㅉ"         printf("sound for %s is: jj", yytext);
"ㅏ"         printf("sound for %s is: ah", yytext);
"ㅐ"         printf("sound for %s is: ae", yytext);
"ㅑ"         printf("sound for %s is: ah", yytext);
"ㅔ"         printf("sound for %s is: e", yytext);
"ㅕ"         printf("sound for %s is: yeo", yytext);
"ㅗ"         printf("sound for %s is: oh", yytext);
"ㅘ"         printf("sound for %s is: wah", yytext);
"ㅛ"         printf("sound for %s is: yo", yytext);
"ㅜ"         printf("sound for %s is: ooh", yytext);
"ㅠ"         printf("sound for %s is: you", yytext);
"ㅡ"         printf("sound for %s is: eu", yytext);
"ㅢ"         printf("sound for %s is: wee", yytext);
"ㅓ"         printf("sound for %s is: woh", yytext);
"ㅣ"         printf("sound for %s is: ee", yytext);
"겹"         printf("sound for %s is: kyeob", yytext);
"쾡"         printf("sound for %s is: kwaeng", yytext);

%%

int main()
{

  yylex();
  printf("\n");


  return 0;
}
