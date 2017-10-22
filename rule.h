#ifndef _RULE_H
#define _RULE_H

#include <iostream>
#include <string>
#include <vector>

struct rule {
	double weight;
	std::string lhs;
	std::vector<std::string> rhs;
	rule(double, std::string, std::vector<std::string>);
	operator std::string();
	friend std::ostream& operator<<(std::ostream& o, rule& r);
	bool operator==(const rule& other) const;
};

#endif

