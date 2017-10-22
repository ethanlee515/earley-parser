#ifndef _PARSER_H
#define _PARSER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <memory>
#include "rule.h"
#include "column.h"

class parser {
public:
	parser(std::string grammar);
	std::string parse(std::vector<std::string> sen);
private:
	std::unordered_multimap<std::string, rule> rules;
	std::unique_ptr<column[]> columns;
	void process(std::shared_ptr<entry> e);
	void predict(std::string& nonterminal);
	void scan(std::shared_ptr<entry> e);
	void attach(std::shared_ptr<entry> e);
	int c, n;
	std::vector<std::string> sentence;
	std::string parseTree(int x, std::shared_ptr<entry> e);
};

#endif

