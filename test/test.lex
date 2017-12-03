%{
  #include <unistd.h>
  #include <string.h>
  typedef enum { START_OF_HEADER=256, FROM=257, TO=258, CC=259,
                  PRECEDENCE=260, OTHER=261, NAME=262,
                  END_OF_HEADER=263, EMAIL=264}token_t;
  token_t token, hdr_field;
  char *token_txt;
  void is_it_spam(int points, int msgn);
  int get_email_address(char **user, char **host);
  void hdr_to();
  void hdr_cc();
  void hdr_from();
  int precedence():
  char *my_name;
  int my_name_len;
  int to_me;
  char *to_addr1;
  char *from_addr;
  int body;
%}
%x BODY
%%
^From		return START_OF_HEADER;
^From:          return FROM;
^To:            return TO;
^Cc:            return CC;
^Precedence:    return PRECEDENCE;
^[A-Za-z0-9-]+: return OTHER;
[A-Za-z_0-9\.]+ {
                token_txt = strdup(yytext);
                return NAME;
                }
[A-Za-z_0-9\.]+@[A-Za-z_0-9\.]+ {
                token_txt = strdup(yytext);
                return EMAIL;
                }
^\n             { /* empty line */
		BEGIN BODY;
		body=0;
		return END_OF_HEADER;
		}
.|\n            /* Ignore what we don't understand */ ;
<BODY>.|\n      body++;
<BODY>\nFrom	{ BEGIN 0; yyless(0); /* yyless() breaks the "^" mechanism */ }
%%
