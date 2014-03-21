%{
	#include <stdio.h>
	#include <stdlib.h>
	int yylex(void);
	void yyerror (char const *s) {
   		fprintf (stderr, "%s\n", s);
 	}
%}

%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN 
%token RIGHT_OP LEFT_OP INC_OP DEC_OP PTR_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP 

%token ID DATA_TYPE 
%token IF ELSE WHILE FOR DO 
%token CONTINUE BREAK RETURN 
%token NUM INTEGER CHAR_LIT STRING
 


%%

strt:  					/*empty*/
						|external_declaration strt 
						;

external_declaration: 	function_definition 
						| declaration
						;

declaration: 			DATA_TYPE ID ';'
						| DATA_TYPE ID '=' expr ';'
						| DATA_TYPE ID '[' INTEGER ']' ';'
						;

declaration_list: 		declaration 
						| declaration declaration_list
						;

function_definition:	DATA_TYPE ID '(' arg_list ')' compound_stmts
						;

arg_list:				/* empty */
						| DATA_TYPE ID 
						| DATA_TYPE ID ',' arg_list
						;

compound_stmts:			'{' '}' 
						| '{' stmt_list '}'
						;

stmt_list:				/*empty*/
						|stmt stmt_list
						;

stmt:					declaration_list 
						| compound_stmts
						| conditional_stmt
						| iteration_stmt
						| jump_stmt
						| expr ';'
						;

conditional_stmt:		IF '(' expr ')' stmt 
						| IF '(' expr ')' stmt ELSE stmt 
						;

iteration_stmt:			WHILE '(' expr ')' stmt 
						| DO stmt WHILE '(' expr ')' ';'
						| FOR '(' expr ';' expr ';' expr ')' stmt
						;

jump_stmt:				CONTINUE ';'
						| BREAK ';'
						| RETURN ';'
						| RETURN expr ';'
						;

expr:					NUM 
						| ID 
						| NUM binary_op expr
						| ID binary_op expr
						| ID assignment_op expr
						| NUM relational_op expr
						| ID relational_op expr
						| NUM logical_op expr
						| ID logical_op expr
						;
assignment_op:		 	'='
						| MUL_ASSIGN
						| DIV_ASSIGN
						| MOD_ASSIGN
						| ADD_ASSIGN
						| SUB_ASSIGN
						| AND_ASSIGN
						| XOR_ASSIGN
						| OR_ASSIGN
						;

relational_op:			'<'
						| '>'
						| LE_OP
						| GE_OP
						;

logical_op:				'!'
						| AND_OP
						| OR_OP
						;

binary_op:				'+'
						| '-'
						| '*'
						| '/'
						| '%'
						;
%%

int main(){
	yyparse();
	return 0 ;
}

