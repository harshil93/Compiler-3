%{
	#include "defines.h"
	int lineNo=0;
	void countNewLine();
	
%}

%s HASH

preDir			("#include"[ \t]+.*)|("#define"[ \t]+.*)

lineComment		"//".*
blockComment	"/*"((("*"[^/])?)|[^*])*"*/"
string			\"([^\"]|\\.)*\"
charLit			\'([^\']|\\.)?\'

letter 	[a-zA-Z]
digit [0-9]
ws [ \t\v\f]
digits {digit}+
number {digits}("."{digits})?(E("+"|"-")?{digits})?

illegal {`~@#$_\':?}

dt ("auto"|"char"|"const"|"double"|"float"|"int"|"long"|"short"|"signed"|"static"|"unsigned")

id {letter}({letter}|{digit})*

%%
			
"+"										{printf("@@@@ PLUS ");return PLUS; }
","										{printf("@@@@ COMMA ");return COMMA; }
"*"										{printf("@@@@ MUL ");return MUL; }
"="										{printf("@@@@ EQ ");return EQ; }
"-"										{printf("@@@@ SUB ");return SUB;}
"/"										{printf("@@@@ DIV ");return DIV;}
"("										{printf("@@@@ LP ");return LP; }
")"										{printf("@@@@ RP ");return RP; }
"if"									{printf("@@@@ IF ");return IF;}
"for"									{printf("@@@@ FOR ");return FOR;}
"do"									{printf("@@@@ DO ");return DO;}
"while"									{printf("@@@@ WHILE ");return WHILE;}
"{"										{printf("@@@@ LB ");return LB;}
"}"										{printf("@@@@ RB ");return RB;}
";"										{printf("@@@@ SEMI ");return SEMI;}
"return"								{printf("@@@@ RETURN ");return RETURN;}
"break"									{printf("@@@@ BREAK ");return BREAK;}
"continue"								{printf("@@@@ CONTINUE ");return CONTINUE;}
{dt}									{printf("@@@@ DATA_TYPE ");return DATA_TYPE;}
{number}								{printf("@@@@ NUM ");return NUM;}
{id}									{printf("@@@@ ID ");return ID;}
"\n"									{printf("@@@@ newline ");}
.										{printf("UNKnown "); ECHO;}





%%

