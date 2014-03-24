all:
	flex rules1.lex
	g++ -std=c++11 Grammar.h Grammar.cpp Productions.h Productions.cpp lex.yy.c Main.cpp -lfl