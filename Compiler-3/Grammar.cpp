#include "Grammar.h"
#include <iostream>

using namespace std;

Grammar::Grammar()
{
}

void Grammar::addProduction(string &lhs, vector<string> &rhs)
{
	if (m_nonterminal.find(lhs) != m_nonterminal.end())
		m_grammar[m_nonterminal[lhs]].addRhs(rhs);
	else
		cerr << "Add non-terminal first to your grammar" << endl;
}
void Grammar::setStart(string startSym)
{
	m_startSymbol = startSym;
}
void Grammar::addTerminal(string &ter)
{
	m_terminal[ter] = true;
}

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

void Grammar::buildFollow()
{
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
					auto firstNext = getFirst(prods[j][k+1]);
					for (auto it = firstNext.begin(); it != firstNext.end(); it++)
					{
						if ((*it) != "E")
							m_follow[prods[j][k]].insert(*it);
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
			for (unsigned int  j = 0; j < prods[i].size(); j++)
			{
				cout << prods[i][j] << " ";
			}
			cout << " | ";
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
Grammar::~Grammar()
{
}
