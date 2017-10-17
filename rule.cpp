#include "rule.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::ostream;
using std::string;

rule::operator string() {
	stringstream ss;
	ss << weight << " " << lhs;
	for(string s : rhs)
		ss << " " << s;
	return ss.str();
}

ostream& operator<<(ostream& o, rule r) {
	return o << (string) r;
}

