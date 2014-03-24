#include <iostream>
#include "Grammar.h"
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <stack>
using namespace std;
//extern int yylex();
#define LB 258
#define RB 259
#define LP 260
#define RP 261
#define SEMI 262
#define PLUS 263
#define SUB 264
#define MUL 265
#define DIV 266
#define IF 267
#define WHILE 268
#define DO 269
#define FOR 270
#define RETURN 271
#define CONTINUE 272
#define BREAK 273
#define ID 274
#define NUM 275

int state;
int yylex()
{
	switch (state)
	{
	case 1:
	case 3:
	case 7:
	case 9:
	case 12:
		return ID;
		break;
	case 2:
	case 8:
	case 13:
		return PLUS;
		break;
	case 4:
	case 15:
		return SEMI;
		break;
	case 5:
		return IF;
		break;
	case 6:
		return LP;
		break;
	case 10:
		return RP;
		break;
	case 11:
		return LB;
		break;
	case 14:
		return NUM;
		break;
	case 16:
		return RB;
		break;
	}
	state++;
}

void makeReverseMap(map<int,string> &m){
	 m[258] = "{";
	 m[259] = "}";
	 m[260] = "(";
	 m[261] = ")";
	 m[262] = ";";
	 m[263] = "+";
	 m[264] = "-";
	 m[265] = "*";
	 m[266] = "/";
	 m[267] = "IF";
	 m[268] = "WHILE";
	 m[269] = "DO";
	 m[270] = "FOR";
	 m[271] = "RETURN";
	 m[272] = "CONTINUE";
	 m[273] = "BREAK";
	 m[274] = "ID";
	 m[275] = "NUM";
	 m[0] = "$";
}
int main()
{
	Grammar G;
	string firstLine;
	getline(std::cin,firstLine);
	stringstream fs(firstLine);
	string terminal;
	while (fs >> terminal){
		G.addTerminal(terminal);
	}
	string secondLine;
	getline(std::cin, secondLine);
	stringstream ss(secondLine);
	string nonTerminal;
	ss >> nonTerminal;
	G.setStart(nonTerminal);
	G.addNonTerminal(nonTerminal);
	while (ss >> nonTerminal){
		G.addNonTerminal(nonTerminal);
	}
	
	string line;

	while (getline(std::cin,line)){
		stringstream ss(line);
		string tok;
		string nonTerminal;
		ss >> nonTerminal;
		ss >> tok;
		vector<string> temp;
		while (ss >> tok){
			if (tok != "|")
				temp.push_back(tok);
			else{
				G.addProduction(nonTerminal, temp);
				temp.clear();
			}
		}
		G.addProduction(nonTerminal, temp);
	}

	G.printGrammar();

	cout << "------------------" << endl;

	G.removeLeftRecursion();
	G.printGrammar();

	map<int, string> reverseMap;
	makeReverseMap(reverseMap);
	cout << "-----------------" << endl;
	G.buildFirst();
	G.printFirst();
	cout << "---------------------" << endl;
	G.buildFollow();
	G.printFollow();
	cout << "---------------------" << endl;
	G.buildLL1Table();
	G.printLL1Table();
	cout << "--------------------" << endl;

	/*stack<string> parseStack;
	parseStack.push("$");
	parseStack.push(G.getStart());
	int lexeme = yylex();
	auto parsingTable = G.getParsingTable();
	while (1){
		string top = parseStack.top();
		if (G.isNonTerminal(top)){
			if (parsingTable[top].find(reverseMap[lexeme]) != parsingTable[top].end()){
				int prodno = parsingTable[top][reverseMap[lexeme]];
				auto prods = G.getProductions(top);
				auto prod = prods[prodno];
				parseStack.pop();
				for (int i = prod.size() - 1; i >= 0; i--)
				{
					parseStack.push(prod[i]);
				}
			}
			else{
				cerr << "Parsing Error" << endl;
				return 0;
			}
		}
		else{
			if (reverseMap[lexeme] == top){
				if (!lexeme)
				{
					cout << "Successfully Parsed" << endl;
					return 0;
				}
				else
				{
					parseStack.pop();
					lexeme = yylex();
				}
			}
			else{
				cerr << "Invalid Terminal";
				return 0;
			}
		}
	}*/
	return 0;
}