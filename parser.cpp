#include "parser.h"
#include "column.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <tuple>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <string>
#include <set>

using std::runtime_error;
using std::unordered_multimap;
using std::string;
using std::make_pair;
using std::cout;
using std::cerr;
using std::set;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::vector;
using std::pair;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::make_unique;
using namespace std::string_literals;

parser::parser(string grammar) {
	ifstream file(grammar);
	if(!file.good())
		throw runtime_error("File not found");
	string line;
	getline(file, line);
	while(file.good()) {
		stringstream ss(line);
		double weight;
		string lhs;
		vector<string> rhs;
		ss >> weight;
		weight = -log2(weight);
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

string parser::parse(vector<string> sen) {
	c = 0;
	sentence = sen;
	n = sentence.size();
	columns = make_unique<column[]>(n + 1);

	string root = "ROOT"s;
	predict(root);

	while(c <= n) {
		column& col = columns[c];
		while(col.loc < col.entries.size()) {
			while(col.hasNext())
				process(col.next());
			if(col.pending.size() != 0)	
				col.moveMin();
		}
		++c;
	}


	cerr << "Parsing: " << sentence[0];

	for(int i = 1; i < sentence.size(); ++i) {
		cerr << " " << sentence[i];
	}
	cerr << endl;

	for(int i = 0; i <= n; ++i) {
		cerr << "column " << i << endl;
		cerr << columns[i] << endl;
		
	/*	
		cout << "toAttach = " << endl;
		for(auto it : columns[i].toAttach) {
			cout << it.first << ": " << *it.second << endl;
		}
	*/	
	}

	return "";
}

void parser::process(shared_ptr<entry> e) {
	string s = e->nextItem();
	if(s=="")
		attach(e);
	else {
		if(rules.count(s) > 0)
			predict(s);
		else
			scan(e);
	}
}

void parser::predict(string& nonterminal) {
	if(columns[c].predicting.find(nonterminal) != columns[c].predicting.end())
		return;

	auto its = rules.equal_range(nonterminal);
	for(auto it = its.first; it != its.second; ++it) {
		rule r = (*it).second;
		shared_ptr<entry> e = make_shared<entry>(c, r, 0, r.weight);
		columns[c].insert(e);
	}

	columns[c].predicting.insert(nonterminal);
	columns[c].marks[nonterminal] = set<int>();
}

void parser::scan(shared_ptr<entry> e) {

	if(sentence[c] != e->nextItem() || c >= n)
		return;

	shared_ptr<entry> newEntry = make_shared<entry>(e->begin, e->r, e->dot + 1, e->weight);
	
	columns[c+1].insert(newEntry);
}

void parser::attach(shared_ptr<entry> e) {

	int from = e->begin;
	string constituent = e->r.lhs;

	set<int>& marks = columns[from].marks[constituent];
	if(marks.find(c) != marks.end())
		return;
	marks.insert(c);

	auto its = columns[from].toAttach.equal_range(constituent);

	for(auto it = its.first; it != its.second; ++it) {
		columns[c].combine(e, (*it).second);
	}
}

