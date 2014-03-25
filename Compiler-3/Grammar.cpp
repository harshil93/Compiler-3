#include "Grammar.h"
#include <iostream>

using namespace std;

Grammar::Grammar()
{
}

// Inserts a single production corresponding to an existing non-terminal
// Throws an error if the non-terminal does not exist
void Grammar::addProduction(string &lhs, vector<string> &rhs)
{
	if (m_nonterminal.find(lhs) != m_nonterminal.end())
		m_grammar[m_nonterminal[lhs]].addRhs(rhs);
	else{
		cerr << "Add non-terminal first to your grammar" << endl;
		cerr << lhs<<endl;
		exit(0);
	}
}

// Sets the starting symbol(non-terminal) of the grammar
void Grammar::setStart(string startSym)
{
	m_startSymbol = startSym;
}

// Adds a terminal to the grammar
void Grammar::addTerminal(string &ter)
{
	m_terminal[ter] = true;
}

// Adds a non-terminal to the grammar
// Throws an error if the non-terminal is already present
void Grammar::addNonTerminal(string &nonter){
	if (m_nonterminal.find(nonter) == m_nonterminal.end())
	{
		m_nonterminal[nonter] = m_grammar.size();
		Productions p(nonter);
		m_grammar.push_back(p);
	}
	else{
		cerr << "NON-TERMINAL ADD error" << endl;
	}
}

// Builds the first set of the grammar by iterating over all the symbols
// Sets the first of the terminals to itself
// Sets the first of the non-terminals by calling getFirst()
// only if the first set is already not built
void Grammar::buildFirst()
{
	for (auto it = m_terminal.begin(); it != m_terminal.end(); it++)
	{
		m_first[it->first].insert(it->first);
	}
	for (auto it = m_nonterminal.begin(); it != m_nonterminal.end(); it++)
	{
		if (m_first.find(it->first) == m_first.end()){
			getFirst(it->first);
		}
	}
}

// Returns the first set corresponding to a non-terminal
// Returns directly if the first set already exists
// Else calls getFirst() recursively to build the first set
// Over all the productions corresponding to the non-terminal
// For a particular production calls getFirst() till
// a terminal is encountered or first of a non-terminal does not contain
// an epsilon('E')
set<string> Grammar::getFirst(string nonTerminal)
{
	if (m_first.find(nonTerminal) != m_first.end())
		return m_first[nonTerminal];

	Productions p = m_grammar[m_nonterminal[nonTerminal]];
	auto prods = p.getRhs();

	for (unsigned int i = 0; i < prods.size(); i++)
	{
		unsigned int j;
		for ( j = 0; j < prods[i].size(); j++)
		{
			if (isTerminal(prods[i][j]))
			{
				m_first[nonTerminal].insert(prods[i][j]);
				break;
			}

			auto f = getFirst(prods[i][j]);
			for (auto it = f.begin(); it != f.end(); it++)
			{
				if (*it != "E")
					m_first[nonTerminal].insert(*it);
			}

			if (f.find("E") == f.end())
				break;
			
		}

		if (j == prods[i].size()) m_first[nonTerminal].insert("E");

		
	}

	return m_first[nonTerminal];
}

// Builds the follow set of the grammar by iterating over all the non-terminals
// First insert the '$' in the follow of the start symbol
// Then iterate over all the productions to add First(Y) (except epsilon) to Follow(X)
// if a production of the form A -> XY exists and X is a non-terminal
// After that if Follow(A) is added to the follow(Y)
// Also if First(Y) contains epsilon then Follow(A) is added to Follow(X)
void Grammar::buildFollow()
{

	

	for (size_t i = 0; i < m_grammar.size(); i++)
	{
		set<string> temp;
		m_follow[m_grammar[i].getLhs()] = temp;
	}

	m_follow[m_startSymbol].insert("$");
	
	for (size_t i = 0; i < m_grammar.size(); i++)
	{
		Productions p = m_grammar[i];

		auto prods = p.getRhs();
		for (size_t j = 0; j < prods.size() ; j++)
		{
			for (size_t k = 0; k < prods[j].size() - 1; k++)
			{
				if (m_nonterminal.find(prods[j][k]) != m_nonterminal.end()){
					if (isTerminal(prods[j][k + 1]))
						m_follow[prods[j][k]].insert(prods[j][k + 1]);
					else
					{
						auto firstNext = getFirst(prods[j][k + 1]);
						for (auto it = firstNext.begin(); it != firstNext.end(); it++)
						{
							if ((*it) != "E")
								m_follow[prods[j][k]].insert(*it);
						}
					}
				}
			}
		}
	}

	bool isModified = true;
	while (isModified)
	{
		isModified = false;
		for (size_t i = 0; i < m_grammar.size(); i++)
		{
			Productions p = m_grammar[i];
			auto prods = p.getRhs();
			set<string> followLhs;
			if (m_follow.find(p.getLhs()) != m_follow.end())
				followLhs = m_follow[p.getLhs()];

			for (int j = 0; j < prods.size(); j++)
			{
				for (int k = prods[j].size() - 1; k >=0; k--)
				{
					if (m_nonterminal.find(prods[j][k]) != m_nonterminal.end())
					{
						for (auto it = followLhs.begin(); it != followLhs.end(); it++)
						{
							if (m_follow[prods[j][k]].find(*it) == m_follow[prods[j][k]].end())
							{
								m_follow[prods[j][k]].insert(*it);
								isModified = true;
							}
						}

						auto first = getFirst(prods[j][k]);
						if (first.find("E") == first.end()){
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
		}

		
	}


}

void Grammar::printGrammar()
{
	for (auto it = m_nonterminal.begin(); it != m_nonterminal.end(); it++)
	{
		cout << it->first << " -->";
		Productions p = m_grammar[m_nonterminal[it->first]];
		auto prods = p.getRhs();
		for (unsigned int  i = 0; i < prods.size(); i++)
		{
			cout<<i <<" : ";
			for (unsigned int  j = 0; j < prods[i].size(); j++)
			{
				cout << prods[i][j] << " ";
			}

			cout <<endl<<" | ";
		}
		cout << endl;
	}
}

void Grammar::printFirst()
{
	cout << "First Set of Grammar" << endl;
	for (auto it = m_first.begin(); it != m_first.end(); it++)
	{
		cout << it->first << " : ";
		auto st = it->second;
		for (auto it1 = st.begin(); it1 != st.end(); it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
}

void Grammar::printFollow()
{
	cout << "Follow Set of Grammar" << endl;
	for (auto it = m_follow.begin(); it != m_follow.end(); it++)
	{
		cout << it->first << " : ";
		auto st = it->second;
		for (auto it1 = st.begin(); it1 != st.end(); it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
}

set<string> Grammar::getFollow(string nonTerminal){
	if (m_follow.find(nonTerminal) != m_follow.end())
		return m_follow[nonTerminal];
	else
	{
		cout<<nonTerminal<<endl;
		cerr << "getFollow Error" << endl;
		exit(0);
	}
}

// Get the first corresponding to the rhs of a particular production
// i.e. if A -> PQ | XY then getFirstAlpha() could be called on XY or PQ
set<string> Grammar::getFirstAlpha(vector<string> &alpha)
{
	set<string> retVal;
	size_t i = 0;
	for (; i < alpha.size(); i++)
	{
		set<string> first;
		if (isTerminal(alpha[i])) first.insert(alpha[i]);
		else first = getFirst(alpha[i]);
		bool isEThere = false;
		for (auto it = first.begin(); it != first.end() ; it++)
		{
			if (*it == "E"){
				isEThere = true;
			}
			else{
				retVal.insert(*it);
			}
		}
		if (isEThere == false){
			break;
		}
	}

	if (i == alpha.size())
		retVal.insert("E");

	return retVal;
}

// Builds the LL1 parsing table by iterating over the all the non-terminals
// and to their corresponding productions, then firstAlpha stores the expected terminals
// and corresponding to those teminals ( except epsilon ) the entry in the parsing table 
// is populated with the current production and if this first set contains an epsilon then
// then the entries corresponding to follow of the current non-terminal is also populated
// with the current production
void Grammar::buildLL1Table()
{
	for (auto it = m_nonterminal.begin(); it != m_nonterminal.end(); it++)
	{
		Productions p = m_grammar[m_nonterminal[it->first]];
		auto prods = p.getRhs();
		for (unsigned int i = 0; i < prods.size(); i++)
		{
			auto firstAlpha = getFirstAlpha(prods[i]);
			bool isEThere = false;
			for (auto it1 = firstAlpha.begin(); it1 != firstAlpha.end(); it1++)
			{
				if (*it1 != "E"){
					if (m_table[it->first].find(*it1) == m_table[it->first].end() || m_table[it->first][*it1] == i)
						m_table[it->first][*it1] = i;
					else{
						cerr << "AMBIGUITY " <<endl;
						cout<< it->first << ":" << *it1 <<endl;
						cout<< i << " " <<m_table[it->first][*it1]<< endl;
						exit(0);
					}
				}
				else{
					isEThere = true;
				}
			}

			if (isEThere == true){
				auto followA = getFollow(it->first);
				for (auto it1 = followA.begin(); it1 != followA.end() ; it1++)
				{
					if (m_table[it->first].find(*it1) == m_table[it->first].end() || m_table[it->first][*it1] == i)
						m_table[it->first][*it1] = i;
					else{
						cerr << "AMBIGUITY " <<endl;
						cout<< it->first << ":" << *it1 <<endl;
						cout<< i << " " <<m_table[it->first][*it1]<< endl;
						exit(0);
					}
				}
			}
		}
		
	}
}


void Grammar::printLL1Table(){

	for (auto it = m_table.begin(); it != m_table.end(); it++)
	{
		for (auto it1 = (it->second).begin(); it1 != (it->second).end(); it1++)
		{
			cout << it->first << ":" << it1->first << "\t";
			Productions p = m_grammar[m_nonterminal[it->first]];
			auto prods = p.getRhs();
			for (size_t i = 0; i < prods[it1->second].size(); i++)
			{
				cout << prods[it1->second][i];
			}
			cout << endl;
		}
	}
}

// Removes left recursion from a grammar by iterating over all non-terminals
// First the productions of the form A_i -> A_j B where j < i
// are replaced by A_i -> A_k C where k >= i
// then the direct left recursion is removed
void Grammar::removeLeftRecursion()
{
	for (size_t i = 0; i < m_grammar.size(); i++)
	{
		Productions p = m_grammar[i];
		vector< vector<string> > prods = p.getRhs();
		bool flag = false;
		for (size_t j = 0; j < prods.size(); j++)
		{
			if (isNonTerminal(prods[j][0]) && m_nonterminal[prods[j][0]] < i)
			{
				Productions p1 = m_grammar[m_nonterminal[prods[j][0]]];
				vector< vector<string> > prods1 = p1.getRhs();
				for (size_t k = 0; k < prods1.size(); k++)
				{
					for (size_t l = 1; l < prods[j].size(); l++)
					{
						prods1[k].push_back(prods[j][l]);
					}
					prods.push_back(prods1[k]);
				}
				prods.erase(prods.begin() + j);
				j--;
			}
			else if (isNonTerminal(prods[j][0]) && m_nonterminal[prods[j][0]] == i)
			{
				flag = true;
			}
		}
		if (flag)
		{
			string nonterm = m_grammar[i].getLhs() + "'";
			vector< vector<string> > prods1;
			vector<string> v;
			v.push_back("E");
			prods1.push_back(v);
			for (size_t j = 0; j < prods.size(); j++)
			{
				if (isNonTerminal(prods[j][0]) && m_nonterminal[prods[j][0]] == i)
				{
					if (prods[j].size() != 1)
					{
						prods[j].erase(prods[j].begin());
						prods[j].push_back(nonterm);
						prods1.push_back(prods[j]);
					}
					prods.erase(prods.begin() + j);
					j--;
				}
				else if (prods[j][0] != "E")
				{
					prods[j].push_back(nonterm);
				}
				else if (prods[j][0] == "E")
				{
					prods[j].erase(prods[j].begin());
					prods[j].push_back(nonterm);
				}
			}
			Productions p(nonterm);
			p.setRhs(prods1);
			m_nonterminal[nonterm] = m_grammar.size();
			m_grammar.push_back(p);
		}
		m_grammar[i].setRhs(prods);
	}
}

void Grammar::makeGrammarLeftFactored(){
	for (size_t i = 0; i < m_grammar.size(); i++)
	{
		Productions p = m_grammar[i];
	}
}

string Grammar::getStart(){
	return m_startSymbol;
}

bool Grammar::isNonTerminal(string &s){
	return m_nonterminal.find(s) != m_nonterminal.end();
}

bool Grammar::isTerminal(string &s){
	return m_terminal.find(s) != m_terminal.end();
}

map < string, map<string, int> > Grammar::getParsingTable(){
	return m_table;
}

vector< vector < string> > Grammar::getProductions(string &nonTerminal){
	return m_grammar[m_nonterminal[nonTerminal]].getRhs();
}
Grammar::~Grammar()
{
}
