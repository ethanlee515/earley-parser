#include "rule.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using std::stringstream;
using std::ostream;
using std::string;
using std::vector;

rule::operator string() {
	stringstream ss;
	ss << weight << " " << lhs;
	for(string s : rhs)
		ss << " " << s;
	return ss.str();
}

ostream& operator<<(ostream& o, rule& r) {
	return o << (string) r;
}

rule::rule(double weight, string lhs, vector<string> rhs) : weight(weight), lhs(lhs), rhs(rhs){}

bool rule::operator==(const rule& other) const {
	return weight == other.weight && lhs == other.lhs && rhs == other.rhs;
}
