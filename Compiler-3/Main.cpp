#include <iostream>
#include "Grammar.h"
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <fstream>
#include "defines.h"

using namespace std;

#define PR(X) cout<< #X <<" "<< X << endl;

extern int yylex();

void makeReverseMap(map<int,string> &m){
	 m[LB] = "{";
	 m[RB] = "}";
	 m[LP] = "(";
	 m[RP] = ")";
	 m[COMMA] = ",";
	 m[SEMI] = ";";
	 m[PLUS] = "+";
	 m[SUB] = "-";
	 m[MUL] = "*";
	 m[DIV] = "/";
	 m[EQ] = "=";
	 m[IF] = "IF";
	 m[WHILE] = "WHILE";
	 m[DO] = "DO";
	 m[FOR] = "FOR";
	 m[RETURN] = "RETURN";
	 m[CONTINUE] = "CONTINUE";
	 m[BREAK] = "BREAK";
	 m[NUM] = "NUM";
	 m[ID] = "ID";
	 m[DATA_TYPE] = "DATA_TYPE";
	 m[0] = "$";
}

void printStack(std::vector<string> &v){
	cout<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	Grammar G;

	ifstream gramIn;
	gramIn.open("grammar.txt");

	string firstLine;
	getline(gramIn,firstLine);
	stringstream fs(firstLine);
	string terminal;
	while (fs >> terminal){
		G.addTerminal(terminal);
	}
	string secondLine;
	getline(gramIn, secondLine);
	stringstream ss(secondLine);
	string nonTerminal;
	ss >> nonTerminal;
	G.setStart(nonTerminal);
	G.addNonTerminal(nonTerminal);
	while (ss >> nonTerminal){
		G.addNonTerminal(nonTerminal);
	}
	
	string line;

	while (getline(gramIn,line)){
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
	cout<<"********************************!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
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


	vector<string> parseStack;

	parseStack.push_back("$");
	parseStack.push_back(G.getStart());
	int lexeme = yylex();
	printStack(parseStack);
	auto parsingTable = G.getParsingTable();
	while (1){
		string top = parseStack[parseStack.size() - 1];
		PR(top)
		if (G.isNonTerminal(top)){
			cout<<"lexeme"<<" "<<reverseMap[lexeme]<<endl;
			if (parsingTable[top].find(reverseMap[lexeme]) != parsingTable[top].end()){
				int prodno = parsingTable[top][reverseMap[lexeme]];
				auto prods = G.getProductions(top);
				auto prod = prods[prodno];
				parseStack.pop_back();
				for (int i = prod.size() - 1; i >= 0; i--)
				{
					if(prod[i] != "E")
						parseStack.push_back(prod[i]);
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
					parseStack.pop_back();
					lexeme = yylex();
				}
			}
			else{
				cerr << lexeme <<" Invalid Terminal" << endl;
				return 0;
			}
		}
		printStack(parseStack);
	}
	return 0;
}