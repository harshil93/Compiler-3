%{
	#include "y.tab.h"
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
ws [ \n\t\v\f]
digits {digit}+
number {digits}("."{digits})?(E("+"|"-")?{digits})?

illegal {`~@#$_\':?}

dt ("auto"|"char"|"const"|"double"|"float"|"int"|"long"|"short"|"signed"|"static"|"unsigned")

id {letter}({letter}|{digit})*

%%

{lineComment} 							{}
{blockComment}  						{}
{preDir}								{}
{string}			 					{return STRING;}
{charLit}			 					{return CHAR_LIT;}
{dt}									{return DATA_TYPE;}
{number}								{return NUM;}
{id}									{return ID;}
"+="									{return(ADD_ASSIGN); }
"-="									{return(SUB_ASSIGN); }
"*="									{return(MUL_ASSIGN); }
"/="									{return(DIV_ASSIGN); }
"%="									{return(MOD_ASSIGN); }
"&="									{return(AND_ASSIGN); }
"^="									{return(XOR_ASSIGN); }
"|="									{return(OR_ASSIGN); }
">>"									{return(RIGHT_OP); }
"<<"									{return(LEFT_OP); }
"++"									{return(INC_OP); }
"--"									{return(DEC_OP); }
"->"									{return(PTR_OP); }
"&&"									{return(AND_OP); }
"||"									{return(OR_OP); }
"<="									{return(LE_OP); }
">="									{return(GE_OP); }
"=="									{return(EQ_OP); }
"!="									{return(NE_OP); }
";"										{return(';'); }
("{"|"<%")								{return('{'); }
("}"|"%>")								{return('}'); }
","										{return(','); }
":"										{return(':'); }
"="										{return('='); }
"("										{return('('); }
")"										{return(')'); }
("["|"<:")								{return('['); }
("]"|":>")								{return(']'); }
"."										{return('.'); }
"&"										{return('&'); }
"!"										{return('!'); }
"~"										{return('~'); }
"-"										{return('-'); }
"+"										{return('+'); }
"*"										{return('*'); }
"/"										{return('/'); }
"%"										{return('%'); }
"<"										{return('<'); }
">"										{return('>'); }
"^"										{return('^'); }
"|"										{return('|'); }
"?"										{return('?'); }
"\n"									{}
{ws}									{}
.										{}





%%

void countNewLine()
{
	int i;
	for(i=0; i<yyleng; i++)
	{
		if(*(yytext+i)=='\n') lineNo++;
	}
}
