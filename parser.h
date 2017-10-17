#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "rule.h"

class parser {
public:
	parser(std::string grammar);
	std::string parse(std::string sentence);
private:
	std::unordered_multimap<std::string, rule> rules;

};

