#pragma once
#include <string>
#include <vector>
#include "Productions.h"
#include <map>
#include <set>
using namespace std;
class Grammar
{
	vector < Productions > m_grammar;
	map<string, int> m_nonterminal;
	map<string, bool> m_terminal;
	map<string, set<string>> m_first, m_follow;
	string m_startSymbol;
	map < string, map<string, int> > m_table;
public:
	Grammar();
	void setStart(string startSym);
	void addProduction(string &lhs, vector<string> &rhs);
	void addTerminal(string &ter);
	void addNonTerminal(string &nonter);
	void buildFirst();
	void buildFollow();
	void printFollow();
	set<string> Grammar::getFirst(string nonTerminal);
	void printGrammar();
	void printFirst();
	void buildLL1Table();
	set<string> getFirstAlpha(vector<string> &alpha);
	set<string> getFollow(string nonTerminal);
	void printLL1Table();
	void removeLeftRecursion();
	~Grammar();
};

