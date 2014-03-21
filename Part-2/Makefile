all:
	yacc -d -v -t parser.y
	flex rules.lex
	gcc lex.yy.c y.tab.c y.tab.h -o parser -lfl
