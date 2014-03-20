#include "Productions.h"


Productions::Productions(string &lhs)
{
	m_lhs = lhs;
}

void Productions::addRhs(vector <string> &rhs)
{
	m_rhs.push_back(rhs);
}

vector<vector <string> > Productions::getRhs()
{
	return m_rhs;
}

string Productions::getLhs(){
	return m_lhs;
}

void Productions::setRhs(vector< vector<string> >& rhs)
{
	m_rhs = rhs;
}

Productions::~Productions()
{
}
