/*Spanish to English*/

%%
"color" { printf("color"); }
"sabor" { printf("taste"); }
"bueno" { printf("good"); }
.       { printf("%s", yytext); }

%%
