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
	 m[276] = "INT";
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
				cerr << "Invalid Terminal";
				return 0;
			}
		}
		printStack(parseStack);
	}
	return 0;
}