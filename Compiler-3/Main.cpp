#include <iostream>
#include "Grammar.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

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
	G.removeLeftRecursion();
	G.printGrammar();
	/*cout << "-----------------" << endl;
	G.buildFirst();
	G.printFirst();
	cout << "---------------------" << endl;
	G.buildFollow();
	G.printFollow();
	G.buildLL1Table();
	cout << "--------------------" << endl;
	G.printLL1Table();*/
	return 0;
}