#include "parser.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <tuple>
#include <fstream>
#include <sstream>

using std::unordered_multimap;
using std::string;
using std::make_pair;
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::vector;
using std::pair;

parser::parser(string grammar) {
	ifstream file(grammar);
	string line;
	getline(file, line);
	while(file.good()) {
		stringstream ss(line);
		double weight;
		string lhs;
		vector<string> rhs;
		ss >> weight;
		ss >> lhs;
		while(ss.good()) {
			string s;
			ss >> s;
			rhs.push_back(s);
		}
		rule r = {weight, lhs, rhs};
		rules.insert(make_pair(lhs, r));
		getline(file, line);
	}
}

string parser::parse(string sentence) {
	

	return "";
}
