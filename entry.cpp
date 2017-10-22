#include "entry.h"
#include <sstream>
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::stringstream;
using namespace std::string_literals;

entry::operator string() const {
	stringstream ss;
	ss << index() << " " << weight;
	return ss.str();
}

ostream& operator<<(ostream& o, entry e) {
	return o << (string) e;
}

bool entry::operator==(const entry& other) const {
	return other.begin == begin && other.r == r && other.dot == dot && other.weight == weight;
}

entry::entry(int b, rule r, int dot, double w) : begin(b), r(r), dot(dot), weight(w) {}

string entry::index() const {
	stringstream ss;
	ss << begin << " " << r.lhs;
	for(int i = 0; i < r.rhs.size(); ++i) {
		if(i == dot)
			ss << " .";
		ss << " " << r.rhs[i];
	}
	if(dot == r.rhs.size())	
		ss << " .";
	return ss.str();
}

string entry::nextItem() const {
	if(dot == r.rhs.size())
		return ""s;
	return r.rhs[dot];
}
