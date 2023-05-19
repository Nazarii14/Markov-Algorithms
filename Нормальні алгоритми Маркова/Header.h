#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Rule
{
public:
	vector<string> to_replace;
	vector<string> replacements;
	Rule(vector<string> to_replace, vector<string> replacements)
	{
		this->to_replace = to_replace;
		this->replacements = replacements;
	}
};