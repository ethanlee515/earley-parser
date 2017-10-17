#include <iostream>
#include <string>
#include <vector>

struct rule {
	double weight;
	std::string lhs;
	std::vector<std::string> rhs;
	operator std::string();
	friend std::ostream& operator<<(std::ostream& o, rule r);
};

