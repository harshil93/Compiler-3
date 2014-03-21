all:
	yacc -d parser.y
	flex rules.lex
	gcc lex.yy.c y.tab.c y.tab.h -o main -lfl