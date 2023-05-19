#include "Header.h"

void implement_rule(string& str, Rule rule)
{
	int counter = 0;

	for (int i = 0; i < rule.to_replace.size();)
	{
		int start_index = str.find(rule.to_replace[i]);
		if (start_index != -1)
		{
			str.replace(start_index, rule.to_replace[i].size(), rule.replacements[i]);
			cout << "Iteration " << counter+1 << ": " << str << "\n";
			i = 0;
			counter++;
			if (counter == 1000)
			{
				cout << "Your rules are wrong!" << "\n";
				return;
			}
		}
		else ++i;
	}
	cout << "Result: " << str << "\n\n";
}


int main()
{
	Rule binary_to_decimal({ "1", "|0", "0" }, { "0|", "0||", "" });
	Rule multiplication_1({ "|b", "ab", "b", "*|", "*", "|c", "ac", "c" }, { "ba|", "ba", "", "b*", "c", "c", "c|", "" });
	Rule multiplication_2({ "*11", "*1", "1T", "FT", "F1", "T1", "TF", "F"}, {"T*1", "T", "T1F", "TF", "1F", "T", "F", "1"});
	Rule own_rules({ "ab", "ac", "bc", "c" }, { "c", "b", "a", "a" });
	Rule rules_for_theory_of_algorithms_lesson({ "yyx", "xx", "yyy" }, { "y", "y", ".x" });

	vector<Rule> rules{ binary_to_decimal, multiplication_1, own_rules, rules_for_theory_of_algorithms_lesson, multiplication_2 };
	vector<string> examples = { "101", "||*|||", "acbbca", "xyyxyxxyyyxyxxyx", "111*1111" };

	for (int i = 0; i < rules.size(); i++)
		implement_rule(examples[i], rules[i]);
}