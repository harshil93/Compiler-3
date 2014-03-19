#pragma once
#include <string>
#include <vector>
using namespace std;

class Productions
{
	string m_lhs;
	vector < vector <string> > m_rhs;
public:
	Productions(string &lhs);
	void addRhs(vector<string> &rhs);
	//void removeRhs()
	vector<vector <string> > getRhs();
	string getLhs();
	~Productions();
};

