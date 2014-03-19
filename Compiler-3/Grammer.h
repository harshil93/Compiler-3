#pragma once
#include <vector>
#include <string>
using namespace std;
class Grammer
{
public:
	Grammer();
	void addProduction(string &lhs, vector<string> &rhs);
	~Grammer();
};

